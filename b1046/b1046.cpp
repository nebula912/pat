#include<cstdio>
int main() {
	int N;
	scanf("%d", &N);
	int  a, da, b, db;
	int cupa=0, cupb=0;
	while (N--) {
		scanf("%d%d%d%d", &a, &da, &b, &db);
		int sum = a + b;
		if (da == sum && db != sum)
			cupb++;//��Ӯ
		if (da != sum && db == sum)
			cupa++;//��Ӯ
	}
	printf("%d %d", cupa, cupb);
	return 0;
}