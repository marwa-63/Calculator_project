#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "stdTypes.h"

 #define StackEntry s32
 #define MaxStack 100



typedef struct stack{
    int top;
    StackEntry entry[MaxStack];

}Stack;

typedef struct stack_op{
    int top;
    u8 entry[MaxStack];

}Stack_op;

void CreateStack(Stack*);
int StackFull(Stack *ps);
void Push(StackEntry e , Stack *ps);
void Pop(StackEntry *pe , Stack *ps);
int StackEmpty(Stack *ps);
void StackTop(StackEntry *pe,Stack *ps);
int StackSize(Stack *ps);
void ClearStack(Stack *ps);
void TraverseStack(Stack *ps,void (*pf) (StackEntry));

void CreateStack_op(Stack_op*);
void Push_op(u8 e , Stack_op *ps);
void Pop_op(u8 *pe , Stack_op *ps);
void StackTop_op(u8 *pe,Stack_op *ps);
int StackEmpty_op(Stack_op *ps);
void ClearStack_op(Stack_op *ps);

#endif // STACK_H_INCLUDED
