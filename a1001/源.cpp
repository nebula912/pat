#include<cstdio>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int c = a + b;
    int ans[10];
	int len = 0;
	if (c < 0) { printf("-"); 
	c = -c;
	}
	if (c == 0)ans[len++] = 0;
	while (c ) {
		ans[len++] = c % 10;
		c /= 10;
		
	}
	for (int k = len - 1; k >= 0; k--) {
		printf("%d", ans[k]);
		if (k > 0 && k % 3 == 0)printf(",");
	}
	
	
	return 0;
}