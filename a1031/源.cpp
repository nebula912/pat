#include<cstdio>
#include<cstring>
#include<string>
int main() {
	char str[100];
	scanf("%s",str);
	int n = strlen(str);
	int n1 = (n + 2) / 3, n3 = n1, n2 = n + 2 - n1 - n3;
	for (int i = 0; i < n1-1; i++) {
			printf("%c", str[i]);
		for (int j = 0; j < n2-2; j++) {
				printf(" ");
		}
			printf("%c\n", str[n - i - 1]);
	}
	for (int i = n1-1; i <= n-n3; i++) {
		printf("%c", str[i]);
	}
	return 0;
}