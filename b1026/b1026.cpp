#include<stdio.h>
int main() {
	long c1, c2;
	scanf("%ld%ld",&c1, &c2);
	long time = c2 - c1;
	if (time % 100 >= 50)
		time = time / 100 + 1;
	else
		time /= 100;
	printf("%02ld:%02ld:%02ld", time / 3600, time % 3600 / 60, time % 60);
	return 0;
}