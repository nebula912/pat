#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
struct student
{
	char id[10];
	int virtue;
	int talent;
	int flag;
	int sum;
}stu[100010];
bool cmp(student a, student b) {
	if (a.flag != b.flag) {
		return a.flag < b.flag;
	}
	else
	{
		if (a.sum != b.sum) {
			return a.sum > b.sum;
		}
		else
		{
			if (a.virtue != b.virtue) {
				return a.virtue > b.virtue;
			}
			else
			{
				return strcmp(a.id, b.id) < 0;
			}
		}
	}
}
int main() {
	int n, L, M;
	scanf("%d%d%d", &n, &L, &M);
	int m = n;
	for (int i = 0; i < n; i++) {
		scanf("%s %d%d", stu[i].id, &stu[i].virtue, &stu[i].talent);
		stu[i].sum = stu[i].virtue + stu[i].talent;
		if (stu[i].virtue < L || stu[i].talent < L) {
			stu[i].flag = 5;
			m--;
		}
		else
		{
			if (stu[i].virtue >= M && stu[i].talent >= M) {
				stu[i].flag = 1;
			}
			else
			{
				if (stu[i].virtue >= M && stu[i].talent < M) {
					stu[i].flag = 2;
				}
				else
				{
					if (stu[i].virtue >= stu[i].talent) {
						stu[i].flag = 3;
					}
					else
					{
						stu[i].flag = 4;
					}
				}
			}
		}
	}
	sort(stu, stu+n , cmp);
	printf("%d\n", m);
	for (int i = 0; i < m; i++) {
		printf("%s %d %d\n", stu[i].id, stu[i].virtue, stu[i].talent);
	}
	return 0;
}