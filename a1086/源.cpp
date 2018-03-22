#include<cstdio>
#include<stack>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 50;
int pre[maxn], in[maxn], post[maxn];
struct Node
{
	int data;
	Node* left;
	Node* right;
};
int n;
Node* create(int prel, int prer, int inl, int inr) {
	if (prel > prer) {
		return NULL;
	}
	Node* root = new Node;
	root->data = pre[prel];
	int k;
	for (k = inl; k <= inr; k++) {
		if (in[k] == pre[prel]) {
			break;
		}
	}
	int numleft = k - inl;
	root->left = create(prel + 1, prel + numleft, inl, k - 1);
	root->right = create(prel + numleft + 1, prer, k + 1, inr);
	return root;
}
int num = 0;
void postorder(Node* root) {
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d", root->data);
	num++;
	if (num < n)printf(" ");
}
int main() {
	scanf("%d", &n);
	char str[5];
	stack<int> stack;
	int x, preIndex = 0, inIndex = 0;
	for (int i = 0; i < 2 * n; i++) {
		scanf("%s", str);
		if (strcmp(str, "Push") == 0) {
			scanf("%d", &x);
			pre[preIndex++] = x;
			stack.push(x);
		}
		else
		{
			in[inIndex++] = stack.top();
			stack.pop();
		}
	}
	Node* root = create(0, n - 1, 0, n - 1);
	postorder(root);
	return 0;
}