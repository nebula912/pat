#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int n, k, p;
int maxFacSum = -1;
vector<int> fac, ans, temp;
int pow(int x) {
	int y = 1;
	for (int i = 0; i < p; i++) {
		y *= x;
	}
	return y;
}
void init() {
	int i = 0, temp = 0;
	while (temp <= n)
	{
		fac.push_back(temp);
		temp = pow(++i);
	}
}
void DFS(int index, int nowk, int sum, int facSum) {
	if (sum == n && nowk == k) {
		if (facSum > maxFacSum) {
			ans = temp;
			maxFacSum = facSum;
		}
		return;
	}
	if (sum > n || nowk > k) { return; }
	if (index - 1 >= 0) {
		temp.push_back(index);
		DFS(index, nowk + 1, sum + fac[index], facSum + index);
		temp.pop_back();
		DFS(index - 1, nowk, sum, facSum);
	}
}
int main() {
	scanf("%d%d%d", &n, &k, &p);
	init();
	DFS(fac.size() - 1, 0, 0, 0);
	if (maxFacSum == -1)printf("Impossible\n");
	else
	{
		printf("%d = %d^%d", n, ans[0], p);
		for (int i = 1; i < ans.size(); i++) {
			printf(" + %d^%d", ans[i], p);
		}
	}
	return 0;
}
