#include<stdio.h>

#define LASTIDX 20

int heap[LASTIDX] = { 0,5,3,4,6,1,2,7,19,12 };

int lastIdx = 9; // 초기 힙의 lastIdx

// 스왑함수
//
void Swap(int x, int y)
{
	int temp = heap[x];
	heap[x] = heap[y];
	heap[y] = temp;
}
// Heapify 함수 종속 재귀문
//
void GoProperPos(int curIdx)
{
	int leftIdx = curIdx * 2;
	int rightIdx = leftIdx + 1;
	int largest = curIdx;
	// 가장 큰 인덱스를 찾는다.
	////////////////////////
	if (leftIdx <= lastIdx && heap[leftIdx] > heap[curIdx])     
	{
		largest = leftIdx;
	}
	if (rightIdx <= lastIdx && heap[rightIdx] > heap[largest])
	{
		largest = rightIdx;
	} 
	//////////////////////////

	if (largest == curIdx)
	{
		return;
	}
	else
	{
		Swap(curIdx, largest);
		GoProperPos(largest); // 인덱스를 바꾼 이후 바뀐 값보다 큰값을 자식노드로 가질 수 있기에 끝까지 확인한다.
	}
}

// 정렬이 되어있지않은 배열을 힙 상태로 변경하는 함수
//
void Heapify()
{
	int curIdx = lastIdx / 2;	// 자식을 가지는 마지막 부모노드
	while (curIdx >= 1)
	{
		GoProperPos(curIdx);        // 마지막 부모노드부터 루트노드까지 적절한 자리를 찾게함 
		curIdx--;
	}

}

// 힙에 데이터를 삽입
// 맨 끝에 넣고 값에 따라 상향
//
void Enqueue(int nVal)
{
	int parentIdx;
	int curIdx;
	lastIdx++;
	curIdx = lastIdx;
	heap[curIdx] = nVal;

	parentIdx = curIdx / 2;
	while (1)
	{
		if (heap[parentIdx] >= heap[curIdx])
		{
			return;
		}
		else
		{
			Swap(curIdx, parentIdx);
			curIdx = parentIdx;
			parentIdx /= 2;
			if (parentIdx < 1)
			{
				return;
			}
		}
	}
}
// 루트 노드의 데이터를 추출하는 함수
// 맨 마지막 노드를 루트노드에 넣고 값에 맞게 하향시킴
//
int Dequeue()
{
	int retVal = heap[1];
	heap[1] = heap[lastIdx--];
	
	GoProperPos(1);
	return retVal;
}
// 모든 노드들을 출력한다.
void PrintAll()
{
	for (int i = 1; i <= lastIdx; i++)
	{
		printf("%d  ", heap[i]);
	}
	printf("\n");
}

int main()
{
	PrintAll();
	Heapify();
	PrintAll();
	Enqueue(22);
	PrintAll();
	Dequeue();
	PrintAll();
	return 0;
}