#include<cstdio>

int main() {
	//freopen("input.txt", "r", stdin);
	int T = 1;
	int Case = 1;
	scanf("%d", &T);
	
	while (T--) {
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a + b > c)printf("Case #%d: true\n", Case++);
		else
			printf("Case #%d: false\n", Case++);
	}
	return 0;
}