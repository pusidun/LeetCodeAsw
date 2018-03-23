#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

//rst1保存第一个树的前序遍历结果，rst2保存后面n个树的前序遍历结果，index为这2个数组的下标
int rst1[11];
int rst2[11];
int index = 0;

class BST{
private:
	struct Node{
		int key;
		Node* left;
		Node* right;

		Node(){
			this->key = 0;
			this->left = NULL;
			this->right = NULL;
		}

		Node(int num){
			this->key = num;
			this->left = NULL;
			this->right = NULL;
		}

	};

	Node* root;

	Node* insert(Node* node, int num){
		if (node == NULL){
			count++;
			return new Node(num);
		}
		if (node->key < num){
			node->right = insert(node->right, num);
		}
		else if (node->key > num){
			node->left = insert(node->left, num);
		}
		return node;
	}

    //select用来选择前序遍历结果的保存位置
	void preOrder(Node* node, int select){
		if (node == NULL)
			return;
		if (select == 1)
			rst1[index++] = node->key;
		else if (select == 2)
			rst2[index++] = node->key;
		preOrder(node->left, select);
		preOrder(node->right, select);
	}

	void remove(Node* node){
		if (node == NULL)
			return;
		remove(node->left);
		remove(node->right);
		delete node;
	}
	
public:
	int count;

	BST(){
		root = NULL;
		count = 0;
	}

	~BST(){
		remove(root);
	}

	void insert(int num){
		root = insert(root, num);
	}

	void preOrder(int select){
		preOrder(root, select);
	}
};

void str2int(char* s, int* arr){
	for (int i = 0; s[i] != '\0'; i++){
		arr[i] = s[i] - '0';
	}
}

int main()
{
	int n;  //第一个数n 
	while (scanf("%d", &n) != EOF && n != 0)
	{
		BST raw;  //第一行序列 
		int num = 0;

		//存储序列的数组 
		char tmp[12];
		int raw_seq[11];
		int test_seq[11];

		memset(tmp, 0, sizeof(tmp));
		memset(raw_seq, -1, sizeof(raw_seq));
		scanf("%s", tmp);
		str2int(tmp, raw_seq);

		for (int i = 0; raw_seq[i] != -1 && i<11; i++)
			raw.insert(raw_seq[i]);

		for (int i = 0; i<n; i++){
			BST test;  //接下来的n行序列 
			memset(tmp, 0, sizeof(tmp));
			memset(test_seq, -1, sizeof(test_seq));
			scanf("%s", tmp);
			str2int(tmp, test_seq);
			for (int i = 0; test_seq[i] != -1 && i<11; i++)
				test.insert(test_seq[i]);

			index = 0;
			raw.preOrder(1);
			index = 0;
			test.preOrder(2);
			
			int flag = 0;
			for (int i = 0; i < index; i++)
				if (rst1[i] != rst2[i]){
					flag = 1;
					break;
				}

			if (flag == 1)
				printf("NO\n");
			else if (flag == 0)
				printf("YES\n");
		}
	}
	return 0;
}
