#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 10001;
char str1[maxn];
char str2[maxn];

int main() {
	bool Hashtable[200];
	memset(Hashtable, true, sizeof(Hashtable));
	gets_s(str1);
	gets_s(str2);
	int len = strlen(str2);
	for (int i = 0; i < len; i++) {
		char c = str2[i];
		Hashtable[c] = false;
	}
	len = strlen(str1);
	for (int i = 0; i < len; i++) {
		if (Hashtable[str1[i]] == true) {
			printf("%c", str1[i]);
		}
	}
	return 0;
}