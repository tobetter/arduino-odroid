# Oduino

Arduino core for the ODROID

## Installation

- Install latest Arduino IDE for the Linux ARM from [www.arduino.cc/Main/Software](https://www.arduino.cc/en/Main/Software?target=_blank)
- Installation Guide : [www.arduino.cc/Guide/Linux](https://www.arduino.cc/en/Guide/Linux?target=_blank)
  - ODROID C1/XU4 : ARM 32bit
  - ODROID C2/N2 : ARM 64bit
- Open Terminal and execute   the following command (copy and paste the following command after $):

```bash
$ sudo apt update && sudo apt upgrade -y && sudo apt autoremove -y
```

```bash
$ sudo apt install -y git
```

```bash
$ sudo git clone https://github.com/hardkernel/wiringPi /tmp/wiringPi &&\
  cd /tmp/wiringPi &&\
  ./build
```

```bash
$ git clone https://github.com/hhk7734/oduino.git ~/Arduino/hardware/hardkernel/odroid
```

- If you already opened the Arduino IDE, Close and reopen the Arduino IDE.

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
