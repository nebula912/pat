#include<cstdio>
#include<string>
#include<cstring>
char map[15] = {'0','1','2','3','4','5','6','7','8','9', 'J','Q','K' };
int min(int x, int y) {
	if (x >= y)return y;
	else
	{
		return x;
	}
};
int main() {
	char a[102], b[102], ans[102] = {0};
	scanf("%s %s", a,b);
	int len1 = strlen(a);
	int len2 = strlen(b);
	int count = 0;
	int len;
	if (len1 >= len2)len = len2;
	else
	{
		len = len1;
	}
	for (int i = 1; i <=len; i++) {
		
		if ((b[len2 -i ] - '0') % 2 != 0) {
			ans[len2-i] = (b[len2 - i] - '0' + a[len1 - i] - '0') % 13;
			count++;
		}
		else
		{
			if ((b[len2 - i] - a[len1 - i] ) < 0) {
				ans[len2 - i]= 10 + (b[len2 - i] - '0' + a[len1 - i]-'0' );
				count++;
			}
			else
			{
				ans[len2 - i] = (b[len2 - i] - '0' + a[len1 - i] - '0');
				count++;
			}
		}
	}
	for (int i = 0; i <=len2-count-1 ; i++) {
		ans[i] = b[i];
	}
	for (int i = 0; i < strlen(ans); i++) {
		printf("%c",map[ ans[i]]);
	}
	return 0;
}