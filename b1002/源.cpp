#include<cstdio>
#include<cstring>

#include<string>
char str[1010] ;
char map[10][10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
int main() {
	scanf("%s", str);
	int sum = 0;
	for (int i = 0; i < strlen(str); i++) {
		sum += str[i] - '0';
	}
	char ans[10];
	int num = 0;
	while (sum / 10 != 0) {
		ans[num] = sum % 10;
		num++;
		sum /= 10;
	}
	ans[num] = sum;
	num++;
	while (num--) {
		printf("%s", map[ans[num]]);
		if (num != 0)printf(" ");
		else
		{
			printf("\n");
		}
	}
	return 0;
}