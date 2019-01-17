#include<stdio.h>

#define LASTIDX 20

int heap[LASTIDX] = { 0,5,3,4,6,1,2,7,19,12 };

int lastIdx = 9; // �ʱ� ���� lastIdx

// �����Լ�
//
void Swap(int x, int y)
{
	int temp = heap[x];
	heap[x] = heap[y];
	heap[y] = temp;
}
// Heapify �Լ� ���� ��͹�
//
void GoProperPos(int curIdx)
{
	int leftIdx = curIdx * 2;
	int rightIdx = leftIdx + 1;
	int largest = curIdx;
	// ���� ū �ε����� ã�´�.
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
		GoProperPos(largest); // �ε����� �ٲ� ���� �ٲ� ������ ū���� �ڽĳ��� ���� �� �ֱ⿡ ������ Ȯ���Ѵ�.
	}
}

// ������ �Ǿ��������� �迭�� �� ���·� �����ϴ� �Լ�
//
void Heapify()
{
	int curIdx = lastIdx / 2;	// �ڽ��� ������ ������ �θ���
	while (curIdx >= 1)
	{
		GoProperPos(curIdx);        // ������ �θ������ ��Ʈ������ ������ �ڸ��� ã���� 
		curIdx--;
	}

}

// ���� �����͸� ����
// �� ���� �ְ� ���� ���� ����
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
// ��Ʈ ����� �����͸� �����ϴ� �Լ�
// �� ������ ��带 ��Ʈ��忡 �ְ� ���� �°� �����Ŵ
//
int Dequeue()
{
	int retVal = heap[1];
	heap[1] = heap[lastIdx--];
	
	GoProperPos(1);
	return retVal;
}
// ��� ������ ����Ѵ�.
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