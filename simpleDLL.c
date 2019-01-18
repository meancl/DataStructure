#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
typedef struct node Node;

Node* head = 0;

// add data to DLL by state type
//
void AddToList(int nVal)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = nVal;
	newNode->next = newNode->prev = 0;

	newNode->next = head->next;
	newNode->prev = head;

	if (head->next != 0)
	{
		head->next->prev = newNode;
	}
	head->next = newNode;

	
}

// delete specific data from list 
//
void Delete(int nVal)
{
	Node* curNode = head->next;
	while (curNode != 0)
	{
		if (curNode->data == nVal)
		{
			if (curNode->next != 0)
			{
				curNode->prev->next = curNode->next;
				curNode->next->prev = curNode->prev;
			}
			else
			{
				curNode->prev->next = curNode->next;
			}
			free(curNode);
			return;
		}	
	
		curNode = curNode->next;
	}
}

// Full print List
//
void Print()
{
	Node* curNode = head->next;
	while (curNode != 0)
	{
		printf("%d ", curNode->data);
		curNode = curNode->next;
	}
	printf("\n");
}

int main()
{
	head = (Node*)malloc(sizeof(Node));
	head->next = head->prev = 0;
	AddToList(5);
	AddToList(2);
	AddToList(1);
	AddToList(4);
	AddToList(3);
	Print();
	Delete(4);
	Print();
	Delete(1);
	Print();
	Delete(2);
	Print();
	Delete(5);
	Print();
	printf("==========After Delete Last Node ============\n");
	Delete(3);
	Print();

	
	return 0;
}