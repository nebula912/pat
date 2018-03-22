#include<cstdio>
int main() {
	long long n;
	long long d;
	scanf("%lld%lld", &n, &d);
	bool flag=false;
	long long a[40];
	int i = 0;
	while (n / d != 0) {
		a[i] = n % d;
		i++;
		n=n/d;
	}
	a[i]=n;
	i++;
	int k = i-1;
	while (i--) {
		if (a[i] != a[k - i])break;
		if (i == 0 )flag = true;
	}
	if (flag) {
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	for (int j = 0; j <= k; j++) {
		printf("%lld", a[k - j]);
		if (j != k)printf(" ");
	}
	return 0;
}