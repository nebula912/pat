#include<cstdio>
int dis_n[100010], dis_a[100010];
int main() {
	int N;
	int sum = 0;
	scanf("%d", &N);
	for (int i = 2; i <= N+1; i++) {
		scanf("%d", &dis_n[i]);
		sum += dis_n[i];
		dis_a[i] = sum;
	}
	dis_a[1] = 0;
	int M;
	scanf("%d", &M);
	int left, right;
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &left, &right);

		if (left > right) {
			if (dis_a[left] - dis_a[right] > sum - dis_a[left]+dis_a[right])
			{
				printf("%d\n", sum - dis_a[left]+dis_a[right]);
			}
			else
			{
				printf("%d\n", dis_a[left] - dis_a[right]);
			}
		}
		else
		{
			if (dis_a[right] - dis_a[left] > sum - dis_a[right]+dis_a[left]) {
				printf("%d\n", sum - dis_a[right]+dis_a[left]);
			}
			else
			{
				printf("%d\n", dis_a[right] - dis_a[left]);
			}
		}

	}	return 0;
}