#include "Stack.h"
void CreateStack(Stack *ps)
{
    ps->top=0;
}
int StackFull(Stack *ps)
{
    return ps->top >= MaxStack;
}
void Push(StackEntry e , Stack *ps)
{
    ps->entry[ps->top]=e;
    ps->top++;
}
void Pop(StackEntry *pe , Stack *ps)
{
    *pe=ps->entry[--ps->top];
}

int StackEmpty(Stack *ps)
{
    return !ps->top;
}

void StackTop(StackEntry *pe,Stack *ps)
{
    *pe=ps->entry[ps->top -1];
}

int StackSize(Stack *ps)
{
    return ps->top;
}

void ClearStack(Stack *ps)
{
    ps->top=0;
}

void TraverseStack(Stack *ps,void (*pf) (StackEntry))
{
    for(int i=ps->top;i>0;i--)
    {
        (*pf)(ps->entry[i-1]);
    }
}





void CreateStack_op(Stack_op *op){
	  op->top=0;
}
void Push_op(u8 e , Stack_op *ps){
	 ps->entry[ps->top]=e;
	    ps->top++;
}
void Pop_op(u8 *pe , Stack_op *ps){
	  *pe=ps->entry[--ps->top];
}
void StackTop_op(u8 *pe,Stack_op *ps){
	*pe=ps->entry[ps->top -1];
}
int StackEmpty_op(Stack_op *ps){
	 return !ps->top;
}
void ClearStack_op(Stack_op *ps){
	 ps->top=0;
}
