#include<cstdio>
const int galleon = 17 * 29;
const int sickle = 29;
struct price
{
	int g;
	int s;
	int k;
};
int main() {
	price a, b;
	scanf("%d.%d.%d", &a.g, &a.s, &a.k);
	scanf("%d.%d.%d", &b.g, &b.s, &b.k);
	int change;
	int knut_a = a.g * galleon + a.s * sickle + a.k;
	int knut_b = b.g * galleon + b.s * sickle + b.k;
	change = knut_b - knut_a;
	if (change < 0) {
		printf("-");
		change = -change;
	}
	printf("%d.%d.%d", change / galleon, change%galleon / sickle, change%sickle);
	return 0;
	
}