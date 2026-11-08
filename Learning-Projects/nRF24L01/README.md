# nRF24L01 Wireless Communication

## Overview

This project is a simple wireless communication system built using two Arduino boards and two nRF24L01 transceiver modules.

A button connected to the transmitter Arduino sends a signal wirelessly to the receiver Arduino. When the receiver gets the signal indicating that the button is pressed, it turns on an LED.

The main purpose of this project was to learn how to set up the nRF24L01 modules, become familiar with the RF24 library, and learn how the SPI (Serial Peripheral Interface) data transmission protocol works.

## Demonstration Video

[Watch the project demonstration](https://youtu.be/2nw7uFwLbLg?si=47U6PTdl5JRJqhSc)

## Hardware Setup

The system consists of two separate Arduino circuits:

**Transmitter**

- Arduino board
- nRF24L01 wireless transceiver module
- Push button

**Receiver**

- Arduino board
- nRF24L01 wireless transceiver module
- Green LED

The push button is powered by the transmitter Arduino. Its signal is read through analog pin A1.

Both nRF24L01 modules use the same pin configuration:

- CE: Digital pin 2
- CSN: Digital pin 3

The receiver uses digital pin 8 as the LED output.

The nRF24L01 modules communicate using the SPI interface.

## How It Works

**1. Transmitter**

The transmitter continuously reads the button input through analog pin A1 using `analogRead()`.

When the button is pressed, the input reaches 1023. The Arduino stores this reading as an integer and sends it wirelessly using the `radio.write()` function from the RF24 library.

**2. Wireless Communication**

The two nRF24L01 modules communicate using the same address, `"22030"`, allowing the receiver to receive the data sent by the transmitter.

The transmitter is configured to send data, while the receiver is configured to listen for incoming data.

**3. Receiver**

The receiver continuously checks whether data is available using `radio.available()`.

When a packet is received, the Arduino reads the transmitted integer. If the value is 1023, digital pin 8 is set HIGH, turning on the LED, followed by a 100 ms delay.

Otherwise, digital pin 8 is set LOW, turning the LED off.

## Code

- [Transmitter Code](transmitter.ino)
- [Receiver Code](receiver.ino)

## Learning Goals

This project helped me become familiar with:

- Setting up and configuring nRF24L01 transceiver modules.
- Using the RF24 Arduino library.
- Learning the basics of how SPI protocol works
- Sending and receiving data wirelessly.
