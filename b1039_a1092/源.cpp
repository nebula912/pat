#include<cstdio>	
#include<algorithm>
#include<cstring>
using namespace std;
char shop[1010], eva[1010];
bool IsEmpty(int *str) {
	bool flag = true;
	for (int i = 0; i < 256; i++) {
		if (str[i] != 0) { flag = false; break; }
	}
	return flag;
}
int main() {
	gets(shop);
	gets(eva);
	int extra = 0;
    bool hashtable[256];
	int bead[256];
	memset(hashtable, false, sizeof(hashtable));
	memset(bead, 0, sizeof(bead));
	int len = strlen(eva);
	int need = len;
	for (int i = 0; i < len; i++) {
		char c = eva[i];

		if (c >= 'a'&&c <= 'z') {
			hashtable[c] = true;
			bead[c]++;
		}
		else {
			if (c >= 'A'&&c <= 'Z') {
				hashtable[c] = true;
				bead[c]++;
			}
			else {
				hashtable[c] = true;
				bead[c]++;
			}

		}
	}
	len = strlen(shop);
	
	for (int i = 0; i < len; i++) {
		if (hashtable[shop[i]] == true&&bead[shop[i]]!=0) {
			need--;
			
			bead[shop[i]]--;
		}
		else
		{
			extra++;
		}
	}
	bool check = IsEmpty(bead );
	if (strlen(eva) != 0 &&check==true) {
		printf("Yes %d", extra);
	}
	else
	{
		printf("No %d", need);
	}
	return 0;
}