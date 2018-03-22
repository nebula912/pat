#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1010;
struct Node
{
	int data;
	Node *left, *right;
};

void insert(Node* &root,int data) {
	if (root == NULL) {
		root = new Node;
		root->data = data;
		root->left = root->right = NULL;
		return;
	}
	if (data < root->data)insert(root->left, data);
	else
	{
		insert(root->right, data);
	}
}
void preorder(Node* root,vector<int> &vi) {
	if (root == NULL)return;
	vi.push_back(root->data);
	preorder(root->left, vi);
	preorder(root->right, vi);
}
void mirror_pre(Node* root, vector<int> &vi) {
	if (root == NULL)return;
	vi.push_back(root->data);
	mirror_pre(root->right, vi);
	mirror_pre(root->left, vi);
}
void postorder(Node* root, vector<int> &vi) {
	if (root == NULL)return;
	postorder(root->left, vi);
	postorder(root->right, vi);
	vi.push_back(root->data);
}
void mirror_postorder(Node* root, vector<int> &vi) {
	if (root == NULL)return;
	mirror_postorder(root->right, vi);
	mirror_postorder(root->left, vi);
	vi.push_back(root->data);
}
vector<int> origin, pre, prem, post, postm;
int main() {
	int n;
	scanf("%d", &n);
	int data;
	Node* root = NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		origin.push_back(data);
		insert(root, data);
	}
	preorder(root, pre);
	mirror_pre(root, prem);
	postorder(root, post);
	mirror_postorder(root, postm);
	if (origin == pre) {
		printf("YES\n");
		for (int i = 0; i < post.size(); i++) {
			printf("%d", post[i]);
			if (i < post.size()-1)printf(" ");
		}
	}
	else
	{
		if (origin == prem) {
			printf("YES\n");
			for (int i = 0; i < postm.size(); i++) {
				printf("%d", postm[i]);
				if (i < postm.size()-1)printf(" ");
			}
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}