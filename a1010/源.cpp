#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL map[256];
LL inf = (1LL << 63) - 1;
void init(){
	for (char c = '0'; c <= '9'; c++) {
		map[c] = c - '0';
	 }
	for (char c = 'a'; c <= 'z'; c++) {
		map[c] = c - 'a'+10;
	}
}
LL convertToDecimal(char a[], LL radix, LL t) {
	LL ans = 0;
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		ans = ans * radix + map[a[i]];
		if (ans<0 || ans>t) {
			return -1;
		}
	}
	return ans;
}
int  cmp(char n2[], LL radix, LL t) {
	int len = strlen(n2);
	LL num = convertToDecimal(n2, radix, t);
	if (num < 0)return 1;
	if (t > num)return -1;
	else
	{
		if (t == num)return 0;
		else
		{
			return 1;
		}
	}
}
LL binarySearch(char n2[], LL left, LL right, LL t) {
	LL mid;
	while (left<=right)
	{
		mid = (left + right) / 2;
		int flag = cmp(n2, mid, t);
		if (flag == 0)return mid;
		else if (flag == -1)left = mid + 1;
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}
int findLargestDigit(char n2[]) {
	int ans = -1;
	int len = strlen(n2);
	for (int i = 0; i < len; i++) {
		if (map[n2[i]] > ans) {
			ans = map[n2[i]];
		}
	}
	return ans + 1;
}
char n1[15], n2[15],temp[15];
int tag, radix;
int main() {
	init();
	scanf("%s %s %d %d", n1, n2, &tag, &radix);
	if (tag == 2) {
		strcpy(temp, n1);
		strcpy(n1, n2);
		strcpy(n2, temp);
	}
	LL t = convertToDecimal(n1, radix, inf);
	LL low = findLargestDigit(n2);
	LL high = max(low, t) + 1;
	LL ans = binarySearch(n2, low, high, t);
	if (ans == -1)printf("Impossible\n");
	else
	{
		printf("%lld\n", ans);
	}
	return 0;
}