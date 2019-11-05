/**
 * \mainpage
 * Tiny and cross-device compatible CRC16 XModem calculator library. Compatible with UKHAS - uCRC16XModemLib
 *
 * Compatible with UKHAS message signing (use offset 2 on full message to skip leading "$").
 *
 *
 * @file uCRC16XModemLib.cpp
 * @copyright Naguissa
 * @author Naguissa
 * @see <a href="https://github.com/Naguissa/uCRC16XModemLib">https://github.com/Naguissa/uCRC16XModemLib</a>
 * @see <a href="https://www.foroelectro.net/librerias-arduino-ide-f29/ucrc16xmodemlib-pequena-libreria-para-calcular-el--t321.html">https://www.foroelectro.net/librerias-arduino-ide-f29/ucrc16xmodemlib-pequena-libreria-para-calcular-el--t321.html</a>
 * @see <a href="mailto:naguissa@foroelectro.net">naguissa@foroelectro.net</a>
 * @version 1.0.0
 */
/** \file uCRC16XModemLib.h
 *   \brief uCRC16XModemLib header file
 */
#ifndef _uCRC16XModemLib_
	/**
	 * \brief Prevent multiple inclussion
	 */
	#define _uCRC16XModemLib_

	#include <Arduino.h>

	/**
	 * \brief CRC16 XModem Polynomial
	 *
	 * Defined value is 0x1021
	 */
	#define uCRC16XModemLib_POLYNOMIAL 0x1021

	class uCRC16XModemLib {
		public:
			uCRC16XModemLib();

			void reset();

			void feedBit(bool);
			void feedByte(char);

			uint16_t getResult();

			uint16_t calculate(const char *);
			uint16_t calculate(const char *, const uint8_t);
		private:
			uint16_t _crc;
			uint8_t _fed8bits = 0;
			char _tmp8bits = 0;
			bool _first = true;
	};

#endif

