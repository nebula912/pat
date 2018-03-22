#include<cstdio>
#include<cstring>
#include<string>
char eng[10][10] = {"zero","one","two","three","four","five","six","seven","eight","nine" };
int main() {
	char num[105];
	scanf("%s", num);
	int sum = 0;
	for (int i = 0; i < strlen(num); i++) {
		sum += num[i] - '0';
	}
	int ans[10];
	int len = 0;
	if (sum == 0) {
		ans[len++] = 0;
	}
	while (sum) {
		ans[len++] = sum % 10;
		sum /= 10;
	}
	for (len--; len>=0; len--) {
		printf("%s", eng[ans[len]]);
		if (len != 0)printf(" ");
	}
	return 0;
}