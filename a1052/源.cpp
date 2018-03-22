#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;
struct Node
{
	int address;
	int key;
	int next;
	bool flag;
}node[maxn];
bool cmp(Node a, Node b) {
	if (a.flag ==false|| b.flag==false)return a.flag > b.flag;
	else return a.key < b.key;
}
int main() {
	int begin, n;
	for (int i = 0; i < maxn; i++) {
		node[i].flag = false;
	}
	freopen("Text.txt", "r", stdin);
	scanf("%d%d", &n, &begin);
	int address, key, next;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &address, &key, &next);
		node[address].address = address;
		node[address].key = key;
		node[address].next = next;
	}
	int p = begin;
	int count = 0;
	while (p != -1)
	{
			count++;
			node[p].flag = true;
		p = node[p].next;
	}
	if (count == 0) {
		printf("0 -1");
	}
	else {
		sort(node, node + maxn, cmp);

		printf("%d %05d\n", count, node[0].address);

		for (int i = 0; i < count; i++) {
			if (i != count - 1) {

				printf("%05d %d %05d\n", node[i].address, node[i].key, node[i + 1].address);

			}
			else printf("%05d %d -1\n", node[i].address, node[i].key);
		}
	}
	return 0;
}