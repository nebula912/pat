#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	int color;
	map<int, int> count;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &color);
			if (count.find(color) != count.end())
				count[color]++;
			else count[color] = 1;
		}
	}
	int ans = 0, max = 0;
	for (map<int, int>::iterator it = count.begin(); it != count.end(); it++) {
		if (it->second > max) {
			ans = it->first; max = it->second;
		}
	}
	printf("%d\n", ans);
	return 0;
}