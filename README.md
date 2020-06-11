# Tiny and cross-device compatible CRC16 XModem calculator library UKHAS.org.uk compatible - uCRC16XModemLib #

Master status:   [![Build Status](https://travis-ci.org/Naguissa/uCRC16XModemLib.svg?branch=master)](https://travis-ci.org/Naguissa/uCRC16XModemLib)

## What is this repository for? ##

Tiny and cross-device compatible CRC16 XModem calculator library

Compatible with UKHAS.org.uk message signing, use offset 2 on full message to skip leading "$".

Supports any microcontroller.



## Usage ##

This library is used with only static methods, you don't need to (and can't) initialize any class object.

You have these methods:
 - *uCRC16XModemLibObject.reset()* : Resets internal state
 - *uCRC16XModemLibObject.feedBit(bool)* : Feeds a bit
 - *uCRC16XModemLibObject.feedByte(char)* : Feeds a byte
 - *uCRC16XModemLibObject.getResult()* : Gets CRC16 in a uint16_t

Library provides also two shorthand methods:
 - uint16_t CRC = *uCRC16XModemLibObject.calculate(MessageCharArray)* : Calculates CRC for a message
 - uint16_t CRC = *uCRC16XModemLibObject.calculate(MessageCharArray, 2)* : Calculates CRC for a message starting from offset 2 (recommended use for UKHAS.org.uk)



## How do I get set up? ##

You can get it from Arduino libraries directly, searching by uCRC16XModemLib.

For manual installation:

 * Get the ZIP from releases link: https://github.com/Naguissa/uCRC16XModemLib/releases
 * Rename to uCRC16XModemLib.zip
 * Install library on Arduino

## Examples ##

Included on example folder, available on Arduino IDE.



## Who do I talk to? ##

 * [Naguissa](https://github.com/Naguissa)
 * https://www.foroelectro.net/librerias-arduino-ide-f29/ucrc16xmodemlib-pequena-libreria-para-calcular-el--t321.html

## Contribute ##

Any code contribution, report or comment are always welcome. Don't hesitate to use GitHub for that.


 * You can sponsor this project using GitHub's Sponsor button: https://github.com/Naguissa/uCRC16XModemLib
 * You can make a donation via PayPal: https://paypal.me/foroelectro


Thanks for your support.


Contributors hall of fame: https://www.foroelectro.net/hall-of-fame-f32/contributors-contribuyentes-t271.html
