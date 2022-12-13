
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*The data port of LCD, to be configured based on project need*/
#define LCD_DATA_PORT		DIO_u8PORTA
/*The control port of LCD, to be configured based on project need*/
#define LCD_CONTROL_PORT	DIO_u8PORTB

/*LCD Register Select pin*/
#define LCD_RS_PIN		DIO_u8PIN0
/*LCD Read/Write pin*/
#define LCD_RW_PIN		DIO_u8PIN1
/*LCD Enable pin*/
#define LCD_E_PIN		DIO_u8PIN2

#define TwoLines_SmallFont	0b00111000

#endif /* LCD_CONFIG_H_ */
