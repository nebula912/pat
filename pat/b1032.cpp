#include<cstdio>
#include<algorithm>
int main() {
	int in;
	int step = 0;
	scanf("%d", &in);
	while (in != 1) {
		if (in % 2 == 0) in /= 2;
		else in = (in * 3 + 1) / 2;
		step++;
	}
	printf("%d", step);
	return 0;
}