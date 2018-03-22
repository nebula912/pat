#include<cstdio>
#include<cstring>
const int maxn = 1010;
int score[maxn] = { 0 };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int team, id;
	int grade = 0;
		scanf("%d-%d %d", &team, &id, &grade);
		score[team] += grade;
	}
	int max = 0,pos=0;
	for (int i = 0; i < maxn; i++) {
		if (score[i] > max) {
			max = score[i];
			pos = i;
		}
	}
	printf("%d %d", pos, score[pos]);
	return 0;
}