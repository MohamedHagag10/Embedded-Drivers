
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/delay.h>

#include "DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

void LCD_voidSendCommand(u8 Copy_u8Command)
{
	/*To send command, set RS pin to LOW*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_u8PIN_LOW);

	/*Enable write mode, set RW pin to LOW*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_u8PIN_LOW);

	/*Set the data port to send the command*/
	DIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Command);

	/*Enable pulse*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8PIN_LOW);
}

void LCD_voidSendCharacter(u8 Copy_u8Character)
{
	/*To send data, set RS pin to HIGH*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_u8PIN_HIGH);

	/*Enable write mode, set RW pin to LOW*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_u8PIN_LOW);

	/*Set the data port to send the character*/
	DIO_voidSetPortValue(LCD_DATA_PORT, Copy_u8Character);

	/*Enable pulse*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8PIN_LOW);

}

void LCD_voidInit(void)
{
	/*Set the data port to output*/
	DIO_voidSetPortDirection(LCD_DATA_PORT, DIO_u8PORT_OUTPUT);
	/*Set the control Pins as output*/
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_u8PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_u8PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT, LCD_E_PIN, DIO_u8PIN_OUTPUT);

	/*Wait for more than 30ms (from data sheet)*/
	_delay_ms(40);
	/*Initialise LCD configuration with: 0b0011NFxx
	 * where N: number of lines, 0: For 1 line and 1 for 2 lines
	 * 		 F: font size, 0: For 5*8 and 1 for 5*11
	 * 		 x: don't care*/
	LCD_voidSendCommand(0b00111000);

	/*Display on/of control, 0b00001DCB
	 * where D: Display, 0:Off and 1:On
	 * 		 C: Cursor, 0:Disable and 1:Enable
	 * 		 B: Cursor blinking, 0: Disable and 1: Enable*/
	LCD_voidSendCommand(0b00001111);

	/*Clear the Display*/
	LCD_voidSendCommand(0b00000001);
}

void LCD_voidSendString(char* Copy_pcString)
{
	u8 Local_u8Counter = 0;
	while(Copy_pcString[Local_u8Counter] != '\0')
	{
		LCD_voidSendCharacter(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}


void LCD_voidPositionSet(u8 Copy_u8RowNum, u8 Copy_u8ColNum)
{
	u8 Local_u8Address;
	/*Check on row number*/
	if(Copy_u8RowNum == 0)
	{
		/*Address location for the first row*/
		Local_u8Address = Copy_u8ColNum;
	}
	else if(Copy_u8RowNum == 1)
	{
		/*Address location for the second row*/
		Local_u8Address = Copy_u8ColNum + 0x40;
	}
	/*Send the command of DDRAM, add 128 because it's required (in data sheet) to
	 * set the MSB by 1*/
	LCD_voidSendCommand(Local_u8Address + 128);
}

void LCD_voidDrawSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8LocationNum, u8 Copy_u8RowNum, u8 Copy_u8ColNum)
{
	u8 Local_u8CGRAMAddr, Local_u8Counter = 0;
	/*Calculate CGRAM address location, each location is 8 bytes size*/
	Local_u8CGRAMAddr = Copy_u8LocationNum * 8;

	/*Accessing CGRAM of LCD
	 * 64 because we need to write the following command: 0b01xxxxxx*/
	LCD_voidSendCommand(Local_u8CGRAMAddr + 64);

	/*Write the required pattern on CGRAM*/
	for(Local_u8Counter = 0 ; Local_u8Counter < 8; Local_u8Counter++)
	{
		LCD_voidSendCharacter(Copy_pu8Pattern[Local_u8Counter]);
	}
	/*Send the pattern to DDRAM*/
	LCD_voidPositionSet(Copy_u8RowNum, Copy_u8ColNum);

	/*Display the data on LCD*/
	LCD_voidSendCharacter(Copy_u8LocationNum);
}
