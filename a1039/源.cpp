#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 40010;
const int M = 26 * 26 * 26 * 10 + 1;
vector<int> selectedCourse[M];
int getID(char *name) {
	int id = 0;
	for (int i = 0; i < 3; i++) {
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}
int main() {
	char name[5];
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		int course, x;
		scanf("%d%d", &course, &x);
		for (int j = 0; j < x; j++) {
			scanf("%s", name);
			int id = getID(name);
			selectedCourse[id].push_back(course);
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", name);
		int id = getID(name);
		sort(selectedCourse[id].begin(), selectedCourse[id].end());
		printf("%s %d", name, selectedCourse[id].size());
		for (int j = 0; j < selectedCourse[id].size(); j++) {
			printf(" %d", selectedCourse[id][j]);
		}
		printf("\n");
	}
	return 0;
}