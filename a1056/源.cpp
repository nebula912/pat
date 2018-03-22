#include<queue>
#include<cstdio>
#include<algorithm>	
using namespace std;
const int maxn = 1010;
struct mouse
{
	int weight;
	int rank;
}mouse[maxn];
int main() {
	int np, ng, order;
	scanf("%d%d", &np, &ng);
	for (int i = 0; i < np; i++) {
		scanf("%d", &mouse[i].weight);
	}
	queue<int> que;
	for (int i = 0; i < np; i++) {
		scanf("%d", &order);
		que.push(order);
	}
	int temp = np, group;
	while (que.size()!=1)
	{
		if (temp%ng == 0)group = temp / ng;
		else group = temp / ng + 1;
		for (int i = 0; i < group; i++) {
			int k = que.front();
			for (int j = 0; j < ng; j++) {
				if (i*ng + j >= temp)break;
				int front = que.front();
				if (mouse[front].weight > mouse[k].weight) {
					k = front;
				}
				mouse[front].rank = group + 1;
				que.pop();
			}
			que.push(k);
		}
		temp = group;
	}
	mouse[que.front()].rank = 1;
	for (int i = 0; i < np; i++) {
		printf("%d", mouse[i].rank);
		if (i < np - 1)printf(" ");
	}
	return 0;
}