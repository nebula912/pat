#include<cstdio>
char map[5] = { 'S','H','C','D','J' };
int start[55], order[55], end[55];
int main() {
	int K;//repeat times
	scanf("%d", &K);
	for (int i = 1; i <= 54; i++) {
		start[i] = i;
	} //³õÊ¼»¯	
	for (int i = 1; i <= 54; i++) {
		scanf("%d", &order[i]);
	}//Â¼ÈëË³Ğò	
	for (int step = 0; step < K; step++) {
		for (int i = 1; i <= 54; i++) {
			end[order[i]] = start[i];
		}
		for (int i = 1; i <= 54; i++) {
			start[i] = end[i];
		}
	}
	int count = 0;
	for (int i = 1; i <= 54; i++) {
		printf("%c%d", map[(end[i] - 1) / 13], (end[i] - 1) % 13 + 1);
		count++;
		if (count < 54)printf(" ");
	}
}