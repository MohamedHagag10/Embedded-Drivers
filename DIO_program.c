
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_config.h"
#include "DIO_private.h"

void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinDirection)
{
	//flag, used in debugging and the return of the function will be u8
	//u8 Local_u8ErrorCode = 0;
	if(Copy_u8Pin <= DIO_u8PIN7)
	{
		if(Copy_u8PinDirection == DIO_u8PIN_INPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA: CLR_BIT(DDRA, Copy_u8Pin); break;
			case DIO_u8PORTB: CLR_BIT(DDRB, Copy_u8Pin); break;
			case DIO_u8PORTC: CLR_BIT(DDRC, Copy_u8Pin); break;
			case DIO_u8PORTD: CLR_BIT(DDRD, Copy_u8Pin); break;
			//default: Local_u8ErrorCode = 1;
			}
		}
		else if(Copy_u8PinDirection == DIO_u8PIN_OUTPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA: SET_BIT(DDRA, Copy_u8Pin); break;
			case DIO_u8PORTB: SET_BIT(DDRB, Copy_u8Pin); break;
			case DIO_u8PORTC: SET_BIT(DDRC, Copy_u8Pin); break;
			case DIO_u8PORTD: SET_BIT(DDRD, Copy_u8Pin); break;
			//default: Local_u8ErrorCode = 1;
			}
		}
		else{
			//Local_u8ErrorCode = 3;
		}
	}
	else{
		//Local_u8ErrorCode = 2;
	}
	//return Local_u8ErrorCode;
}


void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8PortDirection)
{
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA: DDRA = Copy_u8PortDirection; break;
	case DIO_u8PORTB: DDRB = Copy_u8PortDirection; break;
	case DIO_u8PORTC: DDRC = Copy_u8PortDirection; break;
	case DIO_u8PORTD: DDRD = Copy_u8PortDirection; break;
	}
}

void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue)
{
	if(Copy_u8Pin <= DIO_u8PIN7)
	{
		if(Copy_u8PinValue == DIO_u8PIN_LOW)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA: CLR_BIT(PORTA, Copy_u8Pin); break;
			case DIO_u8PORTB: CLR_BIT(PORTB, Copy_u8Pin); break;
			case DIO_u8PORTC: CLR_BIT(PORTC, Copy_u8Pin); break;
			case DIO_u8PORTD: CLR_BIT(PORTD, Copy_u8Pin); break;
			}
		}
		else if(Copy_u8PinValue == DIO_u8PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA: SET_BIT(PORTA, Copy_u8Pin); break;
			case DIO_u8PORTB: SET_BIT(PORTB, Copy_u8Pin); break;
			case DIO_u8PORTC: SET_BIT(PORTC, Copy_u8Pin); break;
			case DIO_u8PORTD: SET_BIT(PORTD, Copy_u8Pin); break;
			}
		}
		else{

		}
	}
	else{

	}
}

void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8PortValue)
{
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA: PORTA = Copy_u8PortValue; break;
	case DIO_u8PORTB: PORTB = Copy_u8PortValue; break;
	case DIO_u8PORTC: PORTC = Copy_u8PortValue; break;
	case DIO_u8PORTD: PORTD = Copy_u8PortValue; break;
	}

}

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8PinVal = 0;
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA: Local_u8PinVal = GET_BIT(PINA, Copy_u8Pin); break;
	case DIO_u8PORTB: Local_u8PinVal = GET_BIT(PINB, Copy_u8Pin); break;
	case DIO_u8PORTC: Local_u8PinVal = GET_BIT(PINC, Copy_u8Pin); break;
	case DIO_u8PORTD: Local_u8PinVal = GET_BIT(PIND, Copy_u8Pin); break;
	}
	return Local_u8PinVal;
}

/*
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_pu8PinVal)
{
	//u8 Local_u8PinVal = 0;
	u8 Local_ErrorCode = 0;
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA: *Copy_pu8PinVal = GET_BIT(PINA, Copy_u8Pin); break;
	case DIO_u8PORTB: *Copy_pu8PinVal = GET_BIT(PINB, Copy_u8Pin); break;
	case DIO_u8PORTC: *Copy_pu8PinVal = GET_BIT(PINC, Copy_u8Pin); break;
	case DIO_u8PORTD: *Copy_pu8PinVal = GET_BIT(PIND, Copy_u8Pin); break;
	}
	return Local_ErrorCode;
}
*/

