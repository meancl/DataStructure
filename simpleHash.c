#include<stdio.h>
#include<string.h>

#define MEMBER_SZ 30
struct member 
{
	char name[20];
	int age;
	char number[15];
	struct member* next; //   hash chaining �� ���� SSL ����
};

typedef struct member MEMBER;
MEMBER * hashTable[MEMBER_SZ];
int HashFunC(char * number) // ��ȣ�� �Է¹޾� �� ���ڸ��� ����ASCII ���� ���� MEMBER_SZ �� ������ ������ ���� ��ȯ�ϴ� Hash Function
{
	int sum = 0; 
	int length = strlen(number);
	int i;
	for (i = 0; i < length; i++)
	{
		sum += number[i];
	}
	return (sum % MEMBER_SZ);
}
void AddToHash(char * name, int age, char* number)
{
	MEMBER* new = (MEMBER*)malloc(sizeof(MEMBER));
	strcpy(new->name, name);
	new->age = age;
	strcpy(new->number, number);
	new->next = 0;

	int idx = HashFunC(number);
	if (hashTable[idx] == 0)
	{ 
		// �ƹ��͵� ������ ���ڸ��� �׳� ����
		hashTable[idx] = new;
	}
	else
	{
		MEMBER* tmp = hashTable[idx];
		while (tmp->next != 0)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
		return;
	}
}

void SearchHash(char * number,char * name)	//�ؽ� �Լ��� ���ؼ� �ؽ����̺� ������ ã�´�
{
	int idx = HashFunC(number);
	if (hashTable[idx] == 0)
	{
		printf("There is no number %s\n", number);
	}
	else 
	{
		MEMBER* tmp = hashTable[idx];
		while (strcmp(tmp->name, name) != 0)
		{
			tmp = tmp->next;
			if (tmp == 0)
			{
				printf("There is no  name %s in HashTable", name);
				return;
			}
		}
		printf("%d��° %s��  %d���̰�, �ڵ�����ȣ %s �� ������.\n ", idx, tmp->name, tmp->age, tmp->number);
	}
}
int main()
{
	AddToHash("��ö��",15,"01011112222");
	AddToHash("���Ӱ�", 17 ,"01033334444");
	AddToHash("�Ӳ���",22,"01055556666");
	AddToHash("������",24,"01077778888");
	AddToHash("ȫ�浿", 24, "01077778888");
	SearchHash("01077778888","������");
	

	return 0;
}