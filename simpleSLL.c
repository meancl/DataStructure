#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node * next;
};

struct node* head = 0;

//  리스트의 맨뒤에 노드를 삽입하는 함수
//
void addToSLL(int data)  
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->val = data;
	newNode->next = 0;
	if (head == 0)
	{
		head= newNode;             //아무것도 없으면 헤드에 데이터를 집어 넣고
	}
	else                           //아니면 맨 뒷자리에 노드를 새로운 노드를 삽입한다.
	{
		struct node* nextNode = head;
		while (nextNode->next != 0)
		{
			nextNode = nextNode->next;
		}
		nextNode->next = newNode;
	}
}

//   리스트의 데이터를 처음부터 순서대로 출력하는 함수
//
void PrintList()
{
	struct node * curNode;
	curNode = head;
	while (curNode != 0)
	{
		printf("%d\n", curNode->val);
		curNode = curNode->next;
	}
}

//  모든 노드를 삭제하는 함수 
// 삭제 방법은 동적 할당을 해제 하는 것이다.
//
void Destroy()
{
	struct node* cur;
	cur = head;
	while (cur != 0)
	{
		head = head->next;
		printf("%d is deleting\n",cur->val);
		free(cur);
		cur = head;

	}
}
// 특정 데이터 뒤에다가 새로운 노드를 삽입하는 함수
//
void Insert(int target, int data)
{
	struct node* finder;
	finder = head;
	while (finder != 0)
	{
		if (finder->val == target)
		{
			struct node* newNode = (struct node*)malloc(sizeof(struct node));
			newNode->next = 0;
			newNode->val = data;
			///////////////////// 새로운 노드를 타겟노드 뒤에 추가시키기
			newNode->next = finder->next;
			finder->next = newNode;

			break;
		}
		finder = finder->next;
	}
}
//	특정 데이터의 노드를 삭제하는 함수
//
void removeL(int target)
{
	struct node* delNode;
	struct node* connect;
	if (head->val == target)   // 헤드의 있는 값이 삭제 데이터라면 헤드를 삭제하고 헤드를 다음 노드로 이동시킨다.
	{
		delNode = head;
		head = head->next;
		free(delNode);
		return;
	}
	else                            // 아니면 특정 데이터를 찾고 만약 있다면 그 노드를 삭제시킨다.
	{
		delNode = head;
		while (delNode != 0)
		{
			if (delNode->val == target)
			{
				connect->next = delNode->next;
				free(delNode);
				break;
			}

			connect = delNode;
			delNode = delNode->next;
			
			
		}
	}
}
int main()
{
	addToSLL(1);
	addToSLL(2);
	addToSLL(3);
	addToSLL(4);
	addToSLL(5);

	removeL(1);

	PrintList();

	Destroy();
	return 0; 
}