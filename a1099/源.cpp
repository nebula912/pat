#include<vector>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 106;
int in[maxn];
int num = 0;
int n;
struct Node
{
	int key;
	int left, right;
}node[maxn];

void inorder(int root) {
	if (root == -1)return;
	inorder(node[root].left);
	node[root].key = in[num++];
	inorder(node[root].right);
}
void BFS(int root) {
	queue<int> Q;
	Q.push(root);
	num = 0;
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		printf("%d", node[now].key);
		num++;
		if (num < n)
		{
			printf(" ");
		}
		if (node[now].left != -1)Q.push(node[now].left);
		if (node[now].right != -1)Q.push(node[now].right);
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {

		scanf("%d%d", &node[i].left, &node[i].right);
	
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	sort(in, in + n);
	inorder(0); 
	BFS(0);
	return 0;
    
}