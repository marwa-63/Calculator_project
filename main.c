/*
 * main.c
 *
 *  Created on: Sep 12, 2021
 *      Author: Ahmed El-Gaafrawy
 */
#include "stdTypes.h"
#include "errorStates.h"



#include "DIO_int.h"

#include "LCD_int.h"

#include "Keypad_int.h"

#include "Calc_int.h"






/*
Stack s;
Stack_op ss;
u8 Local_au8infix[100];

#include "util/delay.h"
int Precedent(char op1,char op2)
	{
	    if(op1 =='$') return 1;
	    if( (op1=='*') || (op1=='/') ) return (op2 != '$');
	     if( (op1=='+') || (op1=='-') ) return ( (op2 != '$') && (op2 != '*') && (op2 != '/') );
	     return 0;
	}
int IsDigit(char c)
	{
	    return (c>='0' && c<='9');
	}
	int IsChar(char c)
	{
	    return ((c=='*')||(c=='/')||(c=='+')||(c=='-') );
	}

	s32 Oper(u8 c,s32 op1,s32 op2)
	{
	    s32 val;
	    switch(c){
	        case'+': val=op1+op2;
	                 break;
	        case'-': val=op1-op2;
	                 break;
	        case'*': val=op1*op2;
	                 break;
	        case'/': val=op1/op2;

	                 break;
	    }
	    return val;


	}

void calc(){




	     s32 num=0;u8 op;

	     for(int i=0;Local_au8infix[i] !='\0';i++)
	     {

	         if(IsDigit(Local_au8infix[i]))
	         {

	             num=num*10+(Local_au8infix[i]-'0');
	         }
	         else{
	                Push(num,&s);
	                num=0;
	            if(!StackEmpty_op(&ss))
	            {
	            	  Pop_op(&op,&ss);


	                    s32 op1,op2;
	                    Pop(&op2,&s);
	                    Pop(&op1,&s);
	                    s32 res=Oper(op,op1,op2);
	                    Push(res,&s);


	            }
	            Push_op(Local_au8infix[i],&ss);

	         }


	     }
	     Push(num,&s);
	     while(!StackEmpty_op(&ss))
	     {
	         Pop_op(&op,&ss);
	         //printf("%c\n",op);
	         s32 op1,op2;
	                    Pop(&op2,&s);
	                    //printf("%d\n",op2);
	                    Pop(&op1,&s);
	                    //printf("op%d\n",op1);
	                    s32 res=Oper(op,op1,op2);
	                    Push(res,&s);

	     }
	     s32 res;
	     StackTop(&res,&s);
	     LCD_enuSendCommand(0xc0);
	     LCD_enuDisplayIntegerNum(res);




}
*/


 int main (void)
{
		 Calc_Init();


		while(1)
		{
			Calulator_prog();


		}

	return 0;
}
