#include<cstdio>	
#include<algorithm>
const int maxn = 1006;
using namespace std;
int data[maxn];
int n,num=0;//node_number
const int INF = 100000000;
struct Node
{
	int key;
	int left, right;
}node[maxn];

void postOrder(int root) {
	if (root <= n) {
	      postOrder(2 * root);
		  postOrder(2 * root + 1);
		  printf("%d", node[root].key);
		  if (num++ < n - 1)printf(" ");
		  else
		  {
			  printf("\n");
		  }
	 }
	else
	{
		return;
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	int m;
	scanf("%d%d", &m, &n);
	while (m--)
	{
		int max = -INF, min = INF;
		int key;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &key);
			node[i].key = key;
			if (key >= max)max = key;
			if (key < min)min = key;
		}
		for (int j = n / 2; j >= 1; j--) {
			node[j].left = node[2 * j].key;
			if (2 * j < n)node[j].right = node[2 * j + 1].key;
		}//建树
		if (node[1].key == max) {//max heap
			bool flag=true ;
			for (int k = n / 2; k >= 1; k--) {
				if (2 * k < n) {//有右子树；
					if (node[k].key < node[2 * k].key || node[k].key < node[2 * k + 1].key) {
						printf("Not Heap\n");
						flag = false;
						break;
					}
				}
				if (2 * k == n) {//没有右子树；
					if (node[k].key < node[2 * k].key) {
						printf("Not Heap\n");
						flag = false;
						break;
					}
				}
				
			}
			if(flag==true)printf("Max Heap\n");
			num = 0;
			postOrder(1);
		}
		else if (node[1].key == min) {//min heap;
			bool flag = true;
			for (int k = n / 2; k >= 1; k--) {
				if (2 * k < n) {//有右子树；
					if (node[k].key > node[2 * k].key || node[k].key > node[2 * k + 1].key) {
						printf("Not Heap\n");
						flag = false;
						break;
					}
				}
				if (2 * k == n) {//没有右子树；
					if (node[k].key > node[2 * k].key) {
						printf("Not Heap\n");
						flag = false;
						break;
					}
				}
			}
			if(flag==true)	printf("Min Heap\n");
			num = 0;
			postOrder(1);
		}
		else
		{   
			printf("Not Heap\n");
			num = 0;
			postOrder(1);
		}
	}
	return 0;
}