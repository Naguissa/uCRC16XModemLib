/**
 * \brief Tiny and cross-device compatible CRC16 XModem calculator library. Compatible with UKHAS - uCRC16XModemLib
 *
 * Compatible with UKHAS message signing (use offset 2 on full message to skip leading "$").
 *
 * Simple example
 *
 *
 * @copyright Naguissa
 * @author Naguissa
 * @see <a href="https://github.com/Naguissa/uCRC16XModemLib">https://github.com/Naguissa/uCRC16XModemLib</a>
 * @see <a href="https://www.foroelectro.net/librerias-arduino-ide-f29/rtclib-arduino-libreria-simple-y-eficaz-para-rtc-y-t95.html">https://www.foroelectro.net/librerias-arduino-ide-f29/rtclib-arduino-libreria-simple-y-eficaz-para-rtc-y-t95.html</a>
 * @see <a href="mailto:naguissa@foroelectro.net">naguissa@foroelectro.net</a>
 */

#include "Arduino.h"
#include "uCRC16XModemLib.h"


uCRC16XModemLib crc;


void setup() {
    Serial.begin(57600);
    while (!Serial) {
      ; // wait for serial port to connect. Needed for Leonardo only
    }



	char string[] = "$$hadie,181,10:42:10,54.422829,-6.741293,27799.3,1:10";
	char stringTwo[] = "$$THANK_YOU_SOOOO_MUCH_!!!!";

	Serial.print("The crc of \"");
	Serial.print(string);
	Serial.print("\" is 0x002A. crc16 returned ");

	// As this example is for UKHAS.org.uk we use offset 2 to avoid leading "$"
	Serial.println(crc.calculate(string, 2), HEX);

	Serial.println();

	Serial.print("The crc of \"");
	Serial.print(string);
	Serial.print("\" is 0x9D65. crc16 returned ");

	// As this example is for UKHAS.org.uk we use offset 2 to avoid leading "$"
	Serial.println(crc.calculate(stringTwo, 2), HEX);

	Serial.println();


	Serial.println(" - END -");
	Serial.println();
}


void loop() {
}

