#include<cstdio>
struct Poly
{
	int exp;
	double cof;
}poly[1001];
double ans[2001] = {0.0};
int main() {
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d %lf", &poly[i].exp, &poly[i].cof);
	}
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int exp;
		double cof;
		scanf("%d %lf", &exp, &cof);
		for (int j = 0; j < K; j++) {
			ans[exp + poly[j].exp] += (cof * poly[j].cof)  ;
		}
	}
	int count=0;
	for (int i = 0; i <= 2000; i++) {
		if (ans[i] != 0.0)count++;
	}
	printf("%d ", count);
	for (int i = 2000; i >= 0; i--) {
		if (ans[i] != 0.0) {
			printf("%d %.1lf", i, ans[i]);
			count--;
			if (count != 0)printf(" ");
		}
	}
	return 0;
}