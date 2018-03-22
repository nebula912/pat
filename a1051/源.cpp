#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int arr[maxn];
stack<int> stc;
int main() {
	int m, n, step;
	scanf("%d%d%d", &m ,&n, &step);
	for (int i = 0; i < step; i++) {
		while (!stc.empty()) {
			stc.pop();
		}
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[j]);
		}
		int now = 1;
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			stc.push(i);
			if (stc.size() > m) {
				flag = false;
				break;
			}
			while (!stc.empty() && stc.top() == arr[now]) {
				stc.pop(); now++;
			}
		}
		if (stc.empty() && flag == true) {
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}