/**
 * \class uCRC16XModemLib
 * \brief Tiny and cross-device compatible CRC16 XModem calculator library. Compatible with UKHAS - uCRC16XModemLib
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

#include "uCRC16XModemLib.h"

/**
 * \brief Constructor
 *
 * Reset internal status
 */
uCRC16XModemLib::uCRC16XModemLib() {
	reset();
}



/**
 * \brief Reset internal status
 */
void uCRC16XModemLib::reset() {
	_crc = 0xffff;
	_fed8bits = 0;
	_tmp8bits = 0;
	_first = true;
}


/**
 * \brief Calculate CRC16 bit per bit
 *
 * @param	data_p	Feeded bit
 */
void uCRC16XModemLib::feedBit(bool data_p) {
//	_tmp8bits = (_tmp8bits << 1) | (data_p ? 0x01 : 0x00);
	_tmp8bits = (_tmp8bits << 1);
	if (data_p) {
		_tmp8bits |= 0x01;
	}
	_fed8bits++;

	if (_fed8bits == 8) {
		feedByte((char) _tmp8bits);
		_fed8bits = 0;
	}
}



/**
 * \brief Calculate CRC16 function, feed a byte
 *
 * @param	data_p	Byte to add
 */
void uCRC16XModemLib::feedByte(char data_p) {
	uint8_t i;

	// 1st byte received
	if (_first == true) {
		_crc = 0xffff;
		_first = false;
	}
	_crc = _crc ^ ((uint16_t) data_p << 8);
	for (i = 0; i < 8; i++) {
		if (_crc & 0x8000) {
		  _crc = (_crc << 1) ^ uCRC16XModemLib_POLYNOMIAL;
		} else {
		  _crc <<= 1;
		}
	}
}

/**
 * \brief Get previously calculated result
 *
 * @param	data_p	Pointer to char array
 * @return calculated CRC
 */
uint16_t uCRC16XModemLib::getResult() {
	if (_first == true) {
		return (~_crc);
	}
	return (_crc);
}



/**
 * \brief Calculate CRC16 function of a char array
 *
 * @param	data_p	Pointer to char array
 * @return calculated CRC
 */
uint16_t uCRC16XModemLib::calculate(const char *string) {
	return calculate(string, 0);
}


/**
 * \brief Calculate CRC16 function of a char array with an offset
 *
 * @param	data_p	Pointer to char array
 * @param	offset	offset from the star of char array
 * @return calculated CRC
 */
uint16_t uCRC16XModemLib::calculate(const char *string, const uint8_t offset) {
	size_t i, len = strlen(string);
	reset();
	for (i = offset; i < len; i++) {
		feedByte(string[i]);
	}
  return getResult();
}
