#include<cstdio>

int main() {
	int n;
	scanf("%d", &n);
	int B, S, G;
	B = n / 100;
	S = n / 10 % 10;
	G = n % 10;
	for (int i = 0; i < B; i++) {
		printf("B");
	}
	for (int i = 0; i < S; i++) {
		printf("S");
	}
	for (int i = 1; i <= G; i++) {
		printf("%d",i);
	}
	return 0;
}