/*
 * Calc_int.h
 *
 *  Created on: Dec 5, 2023
 *      Author: HP
 */

#ifndef CALC_INT_H_
#define CALC_INT_H_

void Calc_Init(void);
s32 Precedent(u8 op1,u8 op2);
ES_t Oper(u8 c,s32 op1,s32 op2,s32 *res);
s32 IsDigit(u8 c);
s32 Calc_Res(void);
void Calulator_prog(void);



#endif /* CALC_INT_H_ */
