#include<stdio.h>
#define QUEUE_SZ 30
#define TRUE 1
#define FALSE 0
#define EMPTY -1
int queue[QUEUE_SZ] = { 0, };
int head;
int tail;

// if it is full then return true
//				 otherwise return false
//			
int IsFull()
{
	// return ((head == ((tail+1 )%QUEUE_SZ))?TRUE:FALSE);
	if (head == (tail + 1) % QUEUE_SZ)  // if next of tail is head , then it will be full
	{
		return TRUE;					
	}
	return FALSE;
}
// if it is empty then return true
//				  otherwise return false
//
int IsEmpty()
{
	// return ((head==tail)?TRUE:FALSE)
	if (head == tail)                 // if head is same with tail ,then it is empty 
	{
		return TRUE;
	}
	return FALSE;
}
// check it would be full 
// if it is not ,then enqueue 
//
void Enqueue(int nVal)
{
	if (IsFull() ==TRUE)
	{
		printf("Queue Buffer is full \n");
		return 0;
	}
	// tail = tail+1 ;
	// tail %= QUEUE_SZ ;
	// queue[tail] =nVal;
	queue[(++tail)%QUEUE_SZ] = nVal; // %(module) is for circular queue
}
// check it is empty 
// if it is not ,then Dequeue
int Dequeue()
{
	if (IsEmpty() ==TRUE)
	{
		printf("There is no data\n");
		return EMPTY;
	}
	// head = head+1;
	// head %= QUEUE_SZ ;
	// return queue[head];
	
	return (queue[(++head)%QUEUE_SZ]);
}

int main()
{
	Enqueue(3);
	Enqueue(2);
	Enqueue(1);
	Dequeue();
		
	printf("%d \n", Dequeue());
	return  0;
}