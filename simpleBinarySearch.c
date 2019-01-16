#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int key;

	struct node* left;
	struct node* right;
}Node;
Node * root = 0;

// 트리에 새 노드를 삽입하는 함수
// 부모 노드보다 작은 값을 가지는 노드들은 왼쪽으로
// 크거나 같은 값을 가지는 노드들은 오른쪽으로 삽입
//
void AddToTree(int nVal)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->left = newNode->right = 0;
	newNode->key = nVal;

	if (root == 0)
	{					// 아직 삽입한게 없다면
		root = newNode;
		return;
	}
	else
	{
		Node* temp = root;
		while (1)
		{

			if (temp->key > newNode->key)     // 부모노드가 값이 더 크다면
			{
				if (temp->left == 0)           // 자식 노드가 없다면 
				{
					temp->left = newNode;
					return;
				}
				else
				{
					temp = temp->left;
				}
			}
			else
			{										//부모노드가 값이 더 작다면
				if (temp->right == 0)				// 자식 노드가 없다면
				{
					temp->right = newNode;
					return;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
	}
}
// 값을가진 노드를 찾아내 트리에서 제거하는 함수
//
Node* RemoveNode(Node* node, int delKey)
{
	if (node == 0)              // 삭제할 노드가 트리에 없는경우 
	{
		return 0;
	}
	if (node->key == delKey)
	{
		if (node->left == 0 && node->right == 0)
		{ 
			//자식노드가 없는경우
			free(node);
			return 0;
			
		}
		else if (node->left == 0)
		{
			//오른쪽 자식노드만 가진경우
			Node* retNode = node->right;
			free(node);
			return retNode;
		}
		else if (node->right == 0)
		{
			//왼쪽 자식노드만 가진경우
			Node* retNode = node->left;
			free(node);
			return retNode;
		}
		else
		{ // 자식노드가 2인경우
			Node* retNode = node->right;
			while (retNode->left != 0)
			{
				retNode = retNode->left;
			}
			node->key = retNode->key;
			node->right = RemoveNode(node->right, retNode->key);
			return node;
		}
	}
	else if(node->key > delKey)
	{										// 삭제노드가 현재노드의 값보다 작은 값을 가질경우
											// 재귀문을 사용해서 삭제 되었을 때의 값인 0 과 아닌경우 그냥 원래노드를 반환해준다.
		node->left = RemoveNode(node->left, delKey);
		return node;
	}
	else
	{										// 삭제노드가 현재노드의 값보다 크거나 같은 값을 가질경우
											// 재귀문을 사용해서 삭제 되었을 때의 값인  0 과 아닌경우 그냥 원래 노드를 반환해준다.
		node->right = RemoveNode(node->right, delKey);
		return node;
	}
}
// 중위순회
//
void InOrderTraversal(Node* curNode)
{
	if (curNode == 0)
	{
		return;
	}
	
	InOrderTraversal(curNode->left);
	printf("%d ", curNode->key);
	InOrderTraversal(curNode->right);

}
// 전위순회
// 
void PreOrderTraversal(Node* curNode)
{
	if (curNode == 0)
	{
		return;
	}
	printf("%d ", curNode->key);
	PreOrderTraversal(curNode->left);
	PreOrderTraversal(curNode->right);
	
}
// 후위순회
//
void PostOrderTraversal(Node* curNode)
{
	if (curNode == 0)
	{
		return;
	}
	PostOrderTraversal(curNode->left);
	PostOrderTraversal(curNode->right);
	printf("%d ", curNode->key);
}
int main()
{
	AddToTree(10);
	AddToTree(7);
	AddToTree(20);
	AddToTree(22);
	AddToTree(21);
	AddToTree(23);
	
	PostOrderTraversal(root);
	printf("\n");
	return 0;
}