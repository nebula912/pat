#include<stdio.h>
#define maxn 1005
int main() {
	int K,count=0;
	int n=0;
	double a=0;
	double coeff[maxn] = {0};
	
		scanf("%d", &K);
		for (int i = 0; i < K; i++) {
			scanf("%d %lf ", &n, &a);
			coeff[n] += a;
		}
		scanf("%d", &K);

		for (int i = 0; i < K; i++) {
			scanf("%d %lf", &n, &a);
			coeff[n] += a;
		}
	for (int i = 0; i < maxn; i++) {
		if (coeff[i] != 0) {
			count++;
		}
		
	}
	printf("%d", count);
	if (count != 0)printf(" ");
	for (int i = 1000; i >=0; i--) {
		if (coeff[i] != 0) {
			printf("%d %.1lf", i, coeff[i]);
			count--;
			if (count != 0)printf(" ");
		}
	}
	return 0;
}