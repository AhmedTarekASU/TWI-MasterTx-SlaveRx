#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "TWI-Mstr-Cond.h"

int main(void)
{
	DDRA = 0xFF;
	i2c_init();
	i2c_start();
	i2c_write(0x40);
	while (1)
	{
		i2c_write(0x55);
		_delay_ms(1000);
		i2c_write(0xAA);
		_delay_ms(1000);
	}
    return 0;
}

