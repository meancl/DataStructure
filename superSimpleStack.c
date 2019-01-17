#include<stdio.h>
#define FULL_STACK_SZ  100
#define TRUE 1
#define FALSE 0 
#define NONE -1
int stack[FULL_STACK_SZ] = { 0, };
int top = NONE;

// if it is empty then return true
//				  otherwise return false
//
int IsEmpty()
{
	if (top == NONE)
	{
		return TRUE;
	}
	return FALSE;
}
// if it is full then return true
//               otherwise return false
//
int IsFull()
{
	if (top == (FULL_STACK_SZ - 1))
	{
		return TRUE;
	}
	return FALSE;
}
// push to stack
//
void Push(int nVal)
{
	if (IsFull())
	{
		return;
	}
	stack[++top] = nVal;
}
// pop from stack 
//
int Pop()
{
	if (IsEmpty())
	{
		return NONE;
	}

	return stack[top--];
}
// print all datas starting top
//
void Print()
{
	for (int i = top; i >= 0; i--)
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}
int main()
{
	Push(2);
	Push(3);
	Push(4);
	Push(5);

	Print();

	Pop();
	Pop();
	Print();
	return 0;
}
