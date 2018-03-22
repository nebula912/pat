#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
const int maxn = 100005;
bool hashtable[maxn] = { 0 };
int hashKey[maxn] = { 0 };
bool isPrime(int n) {
	if (n <= 1)return false;
	int sqr =(int)sqrt(n*1.0);
	for (int i = 2; i <= sqr; i++) {
		if (n%i == 0)return false;
	}
	return true;
}
int main() {
	int msize, n, m, tsize;
	scanf("%d%d%d", &msize, &n, &m);
	tsize = msize;
	while (isPrime(tsize)!=true)
	{
		tsize++;
	}
	for(int i=0;i<n;i++)
	{
		int key;
		scanf("%d", &key);
		int pos = key % tsize;
		if (hashtable[pos] == false) {
			hashtable[pos] = true;
			hashKey[pos] = key;
		}
		else
		{
			int step ;
			for (step = 1; step < tsize; step++) {
				pos = (key + step * step) % tsize;
				if (hashtable[pos] == false) {
					hashtable[pos] = true;
					hashKey[pos] = key;
					break;
				}
			}
			if (step == tsize)printf("%d cannot be inserted.\n", key);
		}
	}
}