#include<cstdio>
int main() {
	int N;
	int arr[1010];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int a[6] = {0};
	int count = 0;
	int sum = 0;
	int max = 0;
	int num = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] % 10 == 0)a[1] += arr[i];
		if (arr[i] % 5 == 1) {
			if (count % 2 == 0)
				a[2] += arr[i];
			else
				a[2] -= arr[i];
			count++;
		}
		if (arr[i] % 5 == 2) {
			a[3]++;
		}
		if (arr[i] % 5 == 3) {
			sum += arr[i];
			num++;
		}
		if (arr[i] % 5 == 4) {
			if (max < arr[i])max = arr[i];
		}
	}
	a[5] = max;
	int flag[6] = { 1,1,1,1,1,1 };
	if (a[1] == 0)flag[1] = 0;
	if (count == 0)flag[2] = 0;
	if (a[3] == 0)flag[3] = 0;
	if (num == 0)flag[4] = 0;
	if (max == 0)flag[5] = 0;
	for (int i = 1; i <= 5; i++) {
		if (flag[i] == 1) {
			if (i == 4) {
				printf("%.1f", (float)sum/num);
			}
			else {
				printf("%d", a[i]);
			}
			if (i != 5)printf(" ");
		}
		else
		{
			printf("N");
			if (i != 5) {
				printf(" ");
			}
		}
	}
		return 0;
	
}