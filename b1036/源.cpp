#include<stdio.h>
int main() {
	int n;
	char c;
	scanf("%d %c", &n, &c);
	int col, row;
	col = n;
	if (n % 2 == 0) {
		row = col / 2;
	}
	else
	{
		row = col / 2 + 1;
	}
	for (int i = 0; i < row-1; i++) {
		if (i == 0) {
			for (int j = 0; j < col; j++)printf("%c", c);
			printf("\n");
		}
		else
		{
			printf("%c", c);
			for (int j = 0; j < col - 2; j++) {
				printf(" ");
			}
			printf("%c\n", c);
		}
	}
	for (int j = 0; j < col; j++)printf("%c", c);
	printf("\n");
	return 0;
}