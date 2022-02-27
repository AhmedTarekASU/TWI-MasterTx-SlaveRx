#include <avr/io.h>
#include<avr/interrupt.h>

void i2c_initSlave(unsigned char slaveAddress)
{
	TWCR = (1<<TWEN);
	TWAR = slaveAddress;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
}
/*-------------------------------------------------------------------------------------------------------*/
void i2c_send(unsigned char data)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
}
/*-------------------------------------------------------------------------------------------------------*/
void i2c_listen()
{
	while((TWCR&(1<<TWINT))==0);
}
/*-------------------------------------------------------------------------------------------------------*/
unsigned char i2c_recieve(unsigned char isLast)
{
	if(isLast==0)
	{
		TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	}
	else
	{
		TWCR = (1<<TWINT)|(1<<TWEN);
	}
	while((TWCR&(1<<TWINT))==0);
	return TWDR;
}
/*--------------------------------------------------------------------------------------------------------*/
