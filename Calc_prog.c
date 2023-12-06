/*
 * Calc_prog.c
 *
 *  Created on: Dec 5, 2023
 *      Author: HP
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "Calc_int.h"
#include "Stack.h"

#include "DIO_int.h"
#include "LCD_int.h"
#include "Keypad_int.h"




u8 Exper[100];
u8 Error_Message[10]="ERROR!!";
u8 i=0;
Stack s_num;
Stack_op s_op;


s32 Precedent(u8 op1,u8 op2)
{
    if(op1 =='$') return 1;
    if( (op1=='*') || (op1=='/') ) return (op2 != '$');
     if( (op1=='+') || (op1=='-') ) return ( (op2 != '$') && (op2 != '*') && (op2 != '/') );
     return 0;
}
s32 IsDigit(u8 c)
{
    return (c>='0' && c<='9');
}


ES_t Oper(u8 c,s32 op1,s32 op2,s32 *res)
{
	 ES_t Local_errorstate=ES_OK;

    switch(c){
        case'+': *res=op1+op2;
                 break;
        case'-': *res=op1-op2;
                 break;
        case'*': *res=op1*op2;
                 break;
        case'/':
        	if(op2==0)
        		Local_errorstate=ES_NOK;
        	else
        	*res=op1/op2;
                 break;
    }
    return Local_errorstate;


}

void Calc_Init()
{
	    DIO_enuInit();
		LCD_enuInit();
		Keypad_enuInit();
		CreateStack(&s_num);
		CreateStack_op(&s_op);


}
s32 Calc_Res()
{
	s32 num=0,res;
	u8 Symbol;
	ES_t Check_div;

	     for(u8 i=0;Exper[i] !='\0';i++)
	     {

	         if(IsDigit(Exper[i]))
	         {

	             num=num*10+(Exper[i]-'0');
	         }
	         else{

	                Push(num,&s_num);
	                num=0;

	            if( !StackEmpty_op(&s_op) )
	            {
	                StackTop_op(&Symbol,&s_op);


	                if( Precedent(Symbol,Exper[i]) )
	                {
	                    s32 op1,op2;

	                    Pop(&op2,&s_num);

	                    Pop(&op1,&s_num);



	                   ES_t Check_div= Oper(Symbol,op1,op2,&res);

	                    if( Check_div==ES_NOK)
	                    {
	                    	 LCD_enuSendCommand(0xc0);
	                    	LCD_enuDisplayString(Error_Message);
	                    	return 0;
	                    }
	                    Push(res,&s_num);
	                   Pop_op(&Symbol,&s_op);

	                }
	            }

	            Push_op(Exper[i],&s_op);
	         }


	     }

	     Push(num,&s_num);

	     while(!StackEmpty_op(&s_op) )
	     {
	         Pop_op(&Symbol,&s_op);

	         s32 op1,op2;

             Pop(&op2,&s_num);
	         Pop(&op1,&s_num );

	          Check_div=Oper(Symbol,op1,op2,&res);
	          if( Check_div==ES_NOK)
	         	    {
	         	       LCD_enuSendCommand(0xc0);
	                   LCD_enuDisplayString(Error_Message);
	                   return 0;
	                   }
	          Push(res,&s_num );

	     }
	     StackTop(&res,&s_num );
	    LCD_enuSendCommand(0xc0);
	    LCD_enuDisplayIntegerNum(res);
	    return 0;





}

void Calulator_prog()
{

	u8 Local_u8Keyval;

		 do
		 {
			 Keypad_enuGetPressedKey(&Local_u8Keyval);

		 }while(Local_u8Keyval==0xff);


			if(Local_u8Keyval == 'c')
			{
				LCD_enuSendCommand(0x01);
				i=0;
				ClearStack(&s_num);
				ClearStack_op(&s_op);
				Exper[0]='\0';

			}
			else if(Local_u8Keyval == '=')
			{
				 Exper[i++]='\0';


				 Calc_Res();


			}
			else{
			LCD_enuDisplayChar(Local_u8Keyval);
			Exper[i++] = Local_u8Keyval;
			}

}

