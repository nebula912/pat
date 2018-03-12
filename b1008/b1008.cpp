#include<cstdio>

int main() {
	int n, m;
	int arr[110];
	int num=0;
	scanf("%d%d", &n, &m);
	m = m % n;
	for (int i = 0; i < n;i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = n - m; i < n; i++) {
		printf("%d", arr[i]);
		num++;
		if (num < n) printf(" ");
	}
	for (int i = 0; i < n - m ; i++) {
		printf("%d", arr[i]);
		num++;
		if (num < n) printf(" ");
	}
	return 0;
}