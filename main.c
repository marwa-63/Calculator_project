 
#include "stdTypes.h"
#include "errorStates.h"



#include "DIO_int.h"

#include "LCD_int.h"

#include "Keypad_int.h"

#include "Calc_int.h"






 int main (void)
{
		 Calc_Init();


		while(1)
		{
			Calulator_prog();


		}

	return 0;
}
