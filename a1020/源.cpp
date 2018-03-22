#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};
vector<int> pre, in, pos;
int n;
Node *create(int posl, int posr, int inl, int inr) {
	if (posl > posr) {
		return NULL;
	 }
	Node *root = new Node;
	root->data = pos[posr];
	int k;
	for (k = inl; k <= inr; k++) {
		if (in[k] == pos[posr]) { break; }
	}
	int numleft = k - inl;
	root->left = create(posl, posl + numleft - 1, inl, k - 1);
	root->right = create(posl + numleft, posr - 1, k + 1, inr);
	return root;
}
int num = 0;
void BFS(Node* root) {
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* now = q.front();
		q.pop();
		printf("%d", now->data);
		num++;
		if (num < n)printf(" ");
		if (now->left != NULL) q.push(now->left);
		if (now->right != NULL) q.push(now->right);
	}
}
int main() {
	scanf("%d", &n);
	int p, q;
	for (int i = 0; i < n; i++) {
		scanf("%d", &p);
		pos.push_back(p);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &q);
		in.push_back(q);
	}
	Node* root = create(0, n - 1, 0, n - 1);
	BFS(root);
	return 0;
}