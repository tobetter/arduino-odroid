/*
  UART.cpp - Hardware serial library for Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  
  Modified 23 November 2006 by David A. Mellis
  Modified 28 September 2010 by Mark Sproul
  Modified 14 August 2012 by Alarus
  Modified 3 December 2013 by Matthijs Kooijman
  Modified 19 June 2019 by Hyeonki hong (odroid support)
*/

#include "UART.h"

#include <wiringSerial.h>
#include <unistd.h>
#include <pthread.h>
UartClass Serial( 0 );
#if defined( ARDUINO_ODROID_N2 )
UartClass Serial1( 1 );
UartClass Serial2( 2 );
#endif
#if defined( ARDUINO_ODROID_XU3 ) || defined( ARDUINO_ODROID_XU4 )
UartClass Serial1( 1 );
#endif

UartClass::UartClass( uint8_t _uart_num )
    : uart_num( _uart_num )
{
}

const int BUFFER_SIZE = 256;
char      buffer[BUFFER_SIZE];
uint16_t  buffer_head = 0;
uint16_t  buffer_tail = 0;
pthread_t stdin_thread;

void *stdin_thread_loop( void *arg )
{
    for( ;; )
    {
        char temp = serialGetchar( STDIN_FILENO );
        if( temp == '\n' )
        {
            buffer[buffer_head] = '\r';
            buffer_head         = ( buffer_head + 1 ) % BUFFER_SIZE;
            if( buffer_head == buffer_tail )
            {
                buffer_tail = ( buffer_tail + 1 ) % BUFFER_SIZE;
            }
        }
        buffer[buffer_head] = temp;
        buffer_head         = ( buffer_head + 1 ) % BUFFER_SIZE;
        if( buffer_head == buffer_tail )
        {
            buffer_tail = ( buffer_tail + 1 ) % BUFFER_SIZE;
        }
    }
}

void UartClass::begin( unsigned long baudrate, uint16_t config )
{
    switch( uart_num )
    {
        case 0:
            fd = STDOUT_FILENO;
            pthread_create( &stdin_thread, NULL, stdin_thread_loop, NULL );
            break;
        case 1:
#if defined( ARDUINO_ODROID_N2 )
            fd = serialOpen( "/dev/ttyS1", baudrate );
#elif defined( ARDUINO_ODROID_XU3 ) || defined( ARDUINO_ODROID_XU4 )
            fd = serialOpen( "/dev/ttySAC0", baudrate );
#endif
            break;
        case 2:
            fd = serialOpen( "/dev/ttyS2", baudrate );
            break;
        default:
            fd = -1;
            break;
    }
}

void UartClass::end()
{
    if( uart_num != 0 )
    {
        serialClose( fd );
    }
}

int UartClass::available( void )
{
    if( uart_num != 0 )
    {
        return serialDataAvail( fd );
    }
    else
    {
        return ( BUFFER_SIZE + buffer_head - buffer_tail ) % BUFFER_SIZE;
    }
}
int UartClass::peek( void ) {}

int UartClass::read( void )
{
    if( uart_num != 0 )
    {
        return serialGetchar( fd );
    }
    else
    {
        if( available() != 0 )
        {
            char temp   = buffer[buffer_tail];
            buffer_tail = ( buffer_tail + 1 ) % BUFFER_SIZE;
            return temp;
        }
        else
        {
            return -1;
        }
    }
}
int UartClass::availableForWrite( void ) {}

void UartClass::flush( void ) {}

size_t UartClass::write( uint8_t c )
{
    serialPutchar( fd, c );
    return 1;
}