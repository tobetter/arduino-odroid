# ODUINO (ODROID to run Arduino)

## About
ODUINO is a project to develop and run Arduino sketch on ODROID boards. With ODUINO, you can write a code with Arduino IDE on an ODROID board and run directly without any other hardware.
- ODROID provides relatively very powerful computing power than generic Arduino boards, even enough to run desktop environment.
- ODROID provides external pin headers that can be configurable as GPIO, I2C, SPI, UART, PWM and ADC and these are the very common hardware features on Arduino boards.
- Arduino provides very powerful frameworks and is easy to learn computer programming.

## Supported boards
These are the target ODROID boards that ODUINO can run, the hardware features supported by Arduino could be not compatible.
- [ODROID-C1](https://wiki.odroid.com/odroid-c1/odroid-c1)
- [ODROID-XU4](https://wiki.odroid.com/odroid-xu4/odroid-xu4)
- [ODROID-C2](https://wiki.odroid.com/odroid-c2/odroid-c2)
- [ODROID-N2](https://wiki.odroid.com/odroid-n2/odroid-n2)
## Installation
- The installation instruction is quite simple, just run the commands below. This commands will install Arduino IDE as well as the modules to run Arduino sketch.
```bash
$ sudo apt update
$ sudo apt install oduino
```
- Currently, the installation package for Debian or Ubuntu are providing.

## Trouble shooting
### ODROID boards are not listed
- If you already have install Arduino IDE and it was running before installing the package **oduino**, Arduino IDE must be restarted.
- If you have installed Arduino already by following the instruction on Arduino page, [Installing latest Arduino IDE for the Linux ARM](https://www.arduino.cc/en/Main/Software?target=_blank), you must copy or link the hardware files for ODROID to the directory of Arduino IDE already installed. For example, if your previous Arduino is installed to **$HOME/Arduino**,
```bash
$ ln -s /usr/share/arduino/hardware/odroid $HOME/Arduino/hardware/
```
## setup

### select board

![board](./image/01.select_board.png)

### select programmer

![programmer](./image/02.select_programmer.png)

## passwd

If you don't want to input your passwd every upload, register user as a nopasswd user on the end of the sudoers file.

```bash
$ sudo visudo

...
odroid ALL=(ALL) NOPASSWD:ALL
```

## todo

- add core source
