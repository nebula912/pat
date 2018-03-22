#include<cstring>
#include<cstdio>
char str[100005];

	bool hashtable[256] ;
int main() {
	memset(hashtable, true, sizeof(hashtable));
	gets_s(str);
	int len1 = strlen(str);
	for (int i = 0; i < len1; i++) {
		if (str[i] >= 'A'&& str[i] <= 'Z') {
			str[i] = str[i] - 'A' + 'a';
		}
		  hashtable[str[i]] = false;
	}
	gets_s(str);
	int len2 = strlen(str);
	for (int i = 0; i < len2; i++) {
		if (str[i] >= 'A'&&str[i] <= 'Z') {
			int low = str[i] - 'A' + 'a';
			if (hashtable[low] == true && hashtable['+'] == true) {
				printf("%c", str[i]);
			}
		}

		else
		{
			if(hashtable[str[i]] == true  ) {
			printf("%c", str[i]);
		}
		} 
	}
	printf("\n");
	return 0;
}