#include<cstdio>	
#include<vector>
#include<algorithm>
using namespace std;
//for avl tree
struct Node
{
	int  key, height;
	Node *left, *right;
};
Node* newNode(int key) {
	Node* node = new Node;
	node->height = 1;
	node->key = key;
	node->left = node->right = NULL;
	return node;
}
int getHeight(Node* root) {
	if (root == NULL)return 0;
	else
	{
		return root->height;
	}
}
int getBalanceFctor(Node* root) {
	return getHeight(root->left) - getHeight(root->right);
}
void updateHeight(Node* root) {
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}
Node* search(Node* &root, int key) {
	if (root == NULL) {
		printf("failed\n"); return;
	}
	if (key == root->key) {
		return root;
	}
	else if (key < root->key) {
		search(root->left, key);
	}
	else
	{
		search(root->right, key);
	}
}
void L(Node* &root) {
	Node* temp=root->right;
	root->right = temp->left;
	temp->left = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void R(Node* &root) {
	Node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(Node* &root,int key) {
	if (root == NULL) {
		root = newNode(key);
		return;
	}
	if (key < root->key) {
		insert(root->left, key);
		updateHeight(root);
		if (getBalanceFctor(root) == 2) {
			if (getBalanceFctor(root->left) == 1)//ll
			{
				R(root);
			}
			else if(getBalanceFctor(root->left)==-1)//lr
			{
				L(root->left);
				R(root);
			}
		}
	}
	else
	{
		insert(root->right, key);
		updateHeight(root);
		if (getBalanceFctor(root) == 2) {
			if (getBalanceFctor(root->right) == 1) { //rl
				R(root->right);
				L(root);
			}
			else
			{
				L(root);
			}
		}
	}
}
Node* createAVL(int data[], int n) {
	Node* root = NULL;
	for (int i = 0; i < n; i++) {
		insert(root, data[i]);
	}
	return root;
}