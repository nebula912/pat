#include<stdio.h>
#define maxn 1005
int main() {
	int cof[maxn] = {0};
	int new_cof[maxn];
	int coeff = 0, exp = 0, count = 0;
	while (scanf("%d%d", &coeff, &exp) != EOF) {
		cof[exp] = coeff;
	}
	/*int i = 1000;
	while (--i) {
		
		new_cof[i - 1] = cof[i] * i;
		if (new_cof[i - 1] != 0) {
			printf("%d %d", new_cof[i - 1], i - 1);
			if (i != 1)printf(" ");
			count++;
		}
	}*/
	for (int i = 0; i <= 1000; i++) {
		new_cof[i] = cof[i + 1] * (i + 1);
		if (new_cof[i] != 0) count++;
	}

	if (count == 0)printf("0 0");
	for (int i = 1000; i >= 0; i--) {
		if (new_cof[i] != 0) {
			printf("%d %d", new_cof[i], i);
			count--;
			if (count != 0)printf(" ");
		}
		
	}
	
	return 0;
}