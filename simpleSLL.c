#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node * next;
};

struct node* head = 0;

//  ����Ʈ�� �ǵڿ� ��带 �����ϴ� �Լ�
//
void addToSLL(int data)  
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->val = data;
	newNode->next = 0;
	if (head == 0)
	{
		head= newNode;             //�ƹ��͵� ������ ��忡 �����͸� ���� �ְ�
	}
	else                           //�ƴϸ� �� ���ڸ��� ��带 ���ο� ��带 �����Ѵ�.
	{
		struct node* nextNode = head;
		while (nextNode->next != 0)
		{
			nextNode = nextNode->next;
		}
		nextNode->next = newNode;
	}
}

//   ����Ʈ�� �����͸� ó������ ������� ����ϴ� �Լ�
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

//  ��� ��带 �����ϴ� �Լ� 
// ���� ����� ���� �Ҵ��� ���� �ϴ� ���̴�.
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
// Ư�� ������ �ڿ��ٰ� ���ο� ��带 �����ϴ� �Լ�
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
			///////////////////// ���ο� ��带 Ÿ�ٳ�� �ڿ� �߰���Ű��
			newNode->next = finder->next;
			finder->next = newNode;

			break;
		}
		finder = finder->next;
	}
}
//	Ư�� �������� ��带 �����ϴ� �Լ�
//
void removeL(int target)
{
	struct node* delNode;
	struct node* connect;
	if (head->val == target)   // ����� �ִ� ���� ���� �����Ͷ�� ��带 �����ϰ� ��带 ���� ���� �̵���Ų��.
	{
		delNode = head;
		head = head->next;
		free(delNode);
		return;
	}
	else                            // �ƴϸ� Ư�� �����͸� ã�� ���� �ִٸ� �� ��带 ������Ų��.
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