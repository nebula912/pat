#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 10;
struct Node
{
	int left, right;
}node[maxn];
bool notroot[maxn] = { false };
int n, num = 0;
void print(int id) {
	printf("%d", id);
	num++;
	if (num < n)printf(" ");
	else
	{
		printf("\n");
	}
}
void inOrder(int root) {
	if (root == -1) {
		return;
	}
	inOrder(node[root].left);
	print( root);
	inOrder(node[root].right);
}
void BFS(int root){
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		print(now);
		if (node[now].left != -1) { q.push(node[now].left); }
		if (node[now].right != -1) { q.push(node[now].right); }
	}
}
void postOrder(int root) {
	if (root == -1) {
		return;
	}
	postOrder(node[root].left);
	postOrder(node[root].right);
	swap(node[root].left, node[root].right);
}
int strToNum(char c) {
	if (c == '-')return -1;
	else
	{
		notroot[c - '0'] = true;
		return c - '0';
	}
}
int findRoot() {
	for (int i = 0; i < n; i++) {
		if (notroot[i] == false) {
			return i;
		}
	}
}
int main() {
	char left, right;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c %c", &left, &right);
		node[i].left = strToNum(left);
		node[i].right = strToNum(right);
	}
	int root = findRoot();
	postOrder(root);
	BFS(root);
	num = 0;
	inOrder(root);
	return 0;
}