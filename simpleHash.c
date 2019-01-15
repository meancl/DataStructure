#include<stdio.h>
#include<string.h>

#define MEMBER_SZ 30
struct member 
{
	char name[20];
	int age;
	char number[15];
	struct member* next; //   hash chaining 을 위해 SSL 구현
};

typedef struct member MEMBER;
MEMBER * hashTable[MEMBER_SZ];
int HashFunC(char * number) // 번호를 입력받아 각 숫자마다 문자ASCII 값을 더해 MEMBER_SZ 로 나누어 나머지 값을 반환하는 Hash Function
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
		// 아무것도 없으면 그자리에 그냥 대입
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

void SearchHash(char * number,char * name)	//해쉬 함수를 통해서 해쉬테이블에 정보를 찾는다
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
		printf("%d번째 %s는  %d살이고, 핸드폰번호 %s 를 가진다.\n ", idx, tmp->name, tmp->age, tmp->number);
	}
}
int main()
{
	AddToHash("김철수",15,"01011112222");
	AddToHash("이임관", 17 ,"01033334444");
	AddToHash("임꺽정",22,"01055556666");
	AddToHash("유도리",24,"01077778888");
	AddToHash("홍길동", 24, "01077778888");
	SearchHash("01077778888","유도리");
	

	return 0;
}