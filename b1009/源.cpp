#include<cstdio>
#include<cstring>
#include<string>

char str[100][100];
int main() {
	int num = 0;
	while (scanf("%s", str[num]) != EOF) {
		num++;	
	}
	for (int i = 0; i < num; i++) {
		printf("%s", str[num - i - 1]);
		if (i < num-1) {
			printf(" ");
		}
	}
	return 0;
}