
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/*Function used to send a command to LCD*/
void LCD_voidSendCommand(u8 Copy_u8Command);
/*Function used to send data(Character) to LCD*/
void LCD_voidSendCharacter(u8 Copy_u8Character);
/*LCD initialisation, Note: Must be called before using LCD functions*/
void LCD_voidInit(void);
/*Function to send string to the LCD*/
void LCD_voidSendString(char* Copy_pu8String);
/*Function to Control the position of the written characters*/
void LCD_voidPositionSet(u8 Copy_u8RowNum, u8 Copy_u8ColNum);
/*Function to write(draw) a special character*/
void LCD_voidDrawSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8LocationNum, u8 Copy_u8RowNum, u8 Copy_u8ColNum);
#endif /* LCD_INTERFACE_H_ */
