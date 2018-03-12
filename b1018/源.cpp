#include<stdio.h>

int change(char a) {
	if (a == 'B') return 0;
	if (a == 'C')return 1;
	if (a == 'J')return 2;
}
int main() {
	int win1 = 0, win2 = 0, draw = 0;

	char data[3] = { 'B','C','J' };
	char c1, c2;
	int k1, k2;
	int N;
	int hand1[3] = { 0 }, hand2[3] = { 0 };
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%c %c", &c1, &c2);
		k1 = change(c1);
		k2 = change(c2);
		if (k1 == k2) {
			draw++;	
		}
		else
		{
			if ((k1 + 1) % 3 == k2) {
				win1++; hand1[k1]++;
			}
			else
			{
				win2++; hand2[k2]++;
			}
		}
	}
	int max1 = 0, max2 = 0;
	for (int i = 0; i < 3; i++) {
		if (hand1[max1] < hand1[i])max1 = i;
		if (hand2[max2] < hand2[i])max2 = i;
	}
	printf("%d %d %d\n", win1, draw, win2);
	printf("%d %d %d\n", win2, draw, win1);
	printf("%c %c", data[max1], data[max2]);
	return 0;
}