#include<stdio.h>
struct info
{
	long long  id;
	int seat;

}student[1001];
int main() {
	int N, M=0;
	scanf("%d", &N);
	long long  id;
	int seat, testseat;
	for (int i = 0; i < N; i++) {
		scanf("%lld %d%d", &id, &testseat, &seat);
		student[testseat].id = id;
		student[testseat].seat = seat;
	}
	scanf("%d", &M);
	int search;
	for (int i = 0; i < M; i++) {
		scanf("%d", &search);
		printf("%lld %d\n", student[search].id, student[search].seat);
	}
	return 0;
}