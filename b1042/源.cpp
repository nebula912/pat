#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
char str[1010];
int main() {
	int count[200];
	memset(count, 0, sizeof(count));
	gets_s(str);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		char c = str[i];
		if (c >= 'A'&&c<= 'Z')c = c + 32;
		count[c]++;
	}
	int max = 0;
	char ans;
	for (int i = 'a'; i <= 'z'; i++) {
		if (count[i] > max) { max = count[i]; ans = i; }
	}
	printf("%c %d", ans, count[ans]);
	return 0;
}