#include<stdio.h>
#include<algorithm>
#include<cmath>

using namespace std;
char map[4] = { 'A','C','M','E' };
struct student
{
	int id;
	int grade[4];
}stu[2005];
int course;
int Rank[10000000][4] = { 0 };
bool cmp(student a, student b) {
	return a.grade[course] > b.grade[course];
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3]) / 3.0) + 0.5;
	}
	for (course = 0; course < 4; course++) {
		sort(stu, stu + n, cmp);
		Rank[stu[0].id][course] = 1;
		for (int i = 1; i < n; i++) {
			if (stu[i].grade[course] == stu[i - 1].grade[course]) {
				Rank[stu[i].id][course] = Rank[stu[i - 1].id][course];
			}
			else
			{
				Rank[stu[i].id][course] = i + 1;
			}
		}

	}
	int query;
	for (int i = 0; i < m; i++) {
		scanf("%d", &query);
		if (Rank[query][0] == 0) {
			printf("N/A\n");
		}
		else
		{
			int k = 0;
			for (int j = 0; j < 4; j++) {
				if (Rank[query][j] < Rank[query][k]) {
					k = j;
				}

			}
			printf("%d %c\n", Rank[query][k], map[k]);
		}
	}
	return 0;
}