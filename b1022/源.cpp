#include<cstdio>
int main() {
	long long a, b, c;
	char str[40] = {0};
	int d;
	scanf("%lld%lld%d", &a, &b, &d);
	c = a + b;
	int i = 0;
	while (c / d != 0) {
		str[i] = c % d+'0';
		c /= d;
		i++;
	}

	str[i] = c + '0';
	i++;
	while (i--) {
		printf("%c", str[i]);
	}
	return 0;
	
	}