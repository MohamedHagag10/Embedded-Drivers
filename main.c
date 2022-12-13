
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"

void main(void)
{
	u8 Local_u8KeyVal;
	LCD_voidInit();
	KEYPAD_voidPinInit();

	while(1)
	{
		Local_u8KeyVal = KEYPAD_u8GetPressedKey();

		if(Local_u8KeyVal != 0xFF)
		{
			LCD_voidSendCharacter(Local_u8KeyVal);
		}
		else{
			//Do Nothing
		}
	}

}
