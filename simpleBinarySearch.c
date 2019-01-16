#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int key;

	struct node* left;
	struct node* right;
}Node;
Node * root = 0;

// Ʈ���� �� ��带 �����ϴ� �Լ�
// �θ� ��庸�� ���� ���� ������ ������ ��������
// ũ�ų� ���� ���� ������ ������ ���������� ����
//
void AddToTree(int nVal)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->left = newNode->right = 0;
	newNode->key = nVal;

	if (root == 0)
	{					// ���� �����Ѱ� ���ٸ�
		root = newNode;
		return;
	}
	else
	{
		Node* temp = root;
		while (1)
		{

			if (temp->key > newNode->key)     // �θ��尡 ���� �� ũ�ٸ�
			{
				if (temp->left == 0)           // �ڽ� ��尡 ���ٸ� 
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
			{										//�θ��尡 ���� �� �۴ٸ�
				if (temp->right == 0)				// �ڽ� ��尡 ���ٸ�
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
// �������� ��带 ã�Ƴ� Ʈ������ �����ϴ� �Լ�
//
Node* RemoveNode(Node* node, int delKey)
{
	if (node == 0)              // ������ ��尡 Ʈ���� ���°�� 
	{
		return 0;
	}
	if (node->key == delKey)
	{
		if (node->left == 0 && node->right == 0)
		{ 
			//�ڽĳ�尡 ���°��
			free(node);
			return 0;
			
		}
		else if (node->left == 0)
		{
			//������ �ڽĳ�常 �������
			Node* retNode = node->right;
			free(node);
			return retNode;
		}
		else if (node->right == 0)
		{
			//���� �ڽĳ�常 �������
			Node* retNode = node->left;
			free(node);
			return retNode;
		}
		else
		{ // �ڽĳ�尡 2�ΰ��
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
	{										// ������尡 �������� ������ ���� ���� �������
											// ��͹��� ����ؼ� ���� �Ǿ��� ���� ���� 0 �� �ƴѰ�� �׳� ������带 ��ȯ���ش�.
		node->left = RemoveNode(node->left, delKey);
		return node;
	}
	else
	{										// ������尡 �������� ������ ũ�ų� ���� ���� �������
											// ��͹��� ����ؼ� ���� �Ǿ��� ���� ����  0 �� �ƴѰ�� �׳� ���� ��带 ��ȯ���ش�.
		node->right = RemoveNode(node->right, delKey);
		return node;
	}
}
// ������ȸ
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
// ������ȸ
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
// ������ȸ
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