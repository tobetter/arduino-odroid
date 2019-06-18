# arduino-odroid

Arduino core for the ODROID

## Installation

- Install latest Arduino IDE for linux ARM from [arduino.cc](https://www.arduino.cc/en/Main/Software)
- Open Terminal and execute the following command (copy->paste and hit enter):

```bash
sudo apt install -y xterm &&\
mkdir -p ~/Arduino/hardware/hardkernel && \
cd ~/Arduino/hardware/hardkernel && \
git clone https://github.com/hhk7734/arduino-odroid.git odroid
```

- Restart Arduino IDE

[https://github.com/arduino/Arduino/wiki/Arduino-IDE-1.5-3rd-party-Hardware-specification](https://github.com/arduino/Arduino/wiki/Arduino-IDE-1.5-3rd-party-Hardware-specification)

- wiringPi installation

```bash
cd &&\
git clone https://github.com/hardkernel/wiringPi &&\
cd wiringPi &&\
sudo ./build
```

## todo

- add core source
- pseudo serial or other method for communication
- start and stop process
- wiringPi
- program pattern shell script
