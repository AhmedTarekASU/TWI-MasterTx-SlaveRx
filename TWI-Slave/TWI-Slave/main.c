#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "TWI-Slave-Config.h"

uint8_t i = 0;
//char sensorVal[8];
int main(void)
{
	DDRA = 0xFF;
	i2c_initSlave(0x40);
	while (1)
	{
		i2c_listen();
		PORTA = i2c_recieve(1);
		
	}
	return 0;
}
