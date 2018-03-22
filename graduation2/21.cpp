#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn = 100005;
int hashtable[maxn];
int find_prime(int n) {
	int prime = n;
	bool flag = false;
	if (n <= 1)prime = 2;
	while (flag == false)
	{
		int k = 2;
		while (prime%k != 0) {
			if (k < (int)sqrt(prime*1.0))k++;
			else
			{
				flag = true;
				break;
			}
		}
		if (flag == false)prime++;
	}
	return prime;
}
int main() {
	memset(hashtable, -1, sizeof(hashtable));
	freopen("Text.txt", "r", stdin);
	int msize, n, m;
	scanf("%d%d%d", &msize, &n, &m);
	int tsize = find_prime(msize);
	for (int i = 0; i < n; i++) {
		int key;
		bool flag = false;
		scanf("%d", &key);
		if (key <= 0) {
			printf("%d cannot be inserted.\n", key);
			continue;
		}
		int pos_origin = key % tsize;
		int pos = pos_origin;
		if (hashtable[pos] == -1) {
			hashtable[pos] = key;
			flag = true;
		}
		else
		{
			for (int j = 1; j <tsize; j++) {
				pos = (pos_origin + j * j) % tsize;
				if (hashtable[pos] == -1) {
					hashtable[pos] = key;
					flag = true;
					break;
				}
			}
		}
		if (flag == false)printf("%d cannot be inserted.\n", key);
	}
	double sum = 0;
	for (int i = 0; i < m; i++) {
		int query;
		int count = 1;//首次查询成功或者为空（不存在于散列表）计一次
		scanf("%d", &query);
		if (query <= 0) {
			sum += count;
			continue;
		}
		int pos_origin = query % tsize;
		int pos = pos_origin;
		if (hashtable[pos] == query) {
			sum += count;
			continue;
		}
		else {
			if (hashtable[pos] == -1) {
				count++;
				sum += count;
				continue;
			}
			else {
				for (int j = 1; j < tsize; j++) {
					pos = (pos_origin + j * j) % tsize;
					if (hashtable[pos] == query) {
						count++;
						break;
					}
					else
					{
						count++;
						if (hashtable[pos] == -1)
						{
							break;
						}
					}
				}
			}
		}
		sum += count;
	}
	double ans = sum / m;
	printf("%.1lf", ans);
	return 0;
}