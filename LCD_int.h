/*
 * LCD_int.h
 *
 *  Created on: Sep 12, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_t LCD_enuInit(void);

ES_t LCD_enuDisplayChar(u8 Copy_u8Data);

ES_t LCD_enuDisplayString(u8 Copy_au8Data[]);

ES_t LCD_enuDisplayIntegerNum(s32 Copy_s32Num);

ES_t LCD_enuSendCommand(u8 Copy_u8Command);


#endif /* LCD_INT_H_ */
