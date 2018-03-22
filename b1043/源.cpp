#include<cstdio>
#include<cstring>
const int maxn = 10010;
char str[maxn], pat[6] = { 'P','A','T','e','s','t' };
int hashtable[6] = { 0 };
int main() {
	gets(str);
	int len = strlen(str);
	int sum = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 6; j++) {
			if (str[i] == pat[j]) {
				hashtable[j]++;
				sum++;
			}
		}
	}
	while (sum > 0) {
		for (int i = 0; i < 6; i++) {
			if (hashtable[i] > 0) {
				printf("%c", pat[i]);
				hashtable[i]--;
				sum--;
			}
		}
	}
	return 0;
}