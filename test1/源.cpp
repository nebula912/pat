#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100010;
struct inst
{
	int tws;
	int rank;
    char name[7];
	int binglie;
	int stu_num;
	bool flag;
}sch[1000];
bool cmp(inst a, inst b) {
	int s = strcmp(a.name, b.name);
	if (a.tws != b.tws) return a.tws > b.tws;
	else
	{
		if (a.stu_num != b.stu_num) return a.stu_num < b.stu_num;
		else return s < 0;
	}
}

int main() {
	for (int i = 0; i < 1000; i++) {
		sch[i].flag = false;
		sch[i].stu_num = 0;
		sch[i].binglie = 0;
		sch[i].tws = 0;
	}
	int n;
	scanf("%d", &n);

	char id[7] = { 0 }, name[7] = { 0 };
	int score;
	int sch_num = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s %d %s", id, &score, name);
		if (id[0] == 'B')score /= 1.5;
		if (id[0] == 'T')score *= 1.5;
		int len = strlen(name);
		char temp[7] = {0};
		for (int j = 0; j < len; j++) {
			char c = name[j];
			if (c <= 'Z'&&c >= 'A')c += 32;
			temp[j]= c;
		}
		strcpy(sch[sch_num].name, temp);
		bool flag = false;
		for ( int k = 0; k < sch_num; k++) {
			if (strcmp(sch[sch_num].name, sch[k].name)==0) {

				sch[k].stu_num++;
				sch[k].tws += score;
				flag = true;
				
				break;
			}
		}
		if (sch[sch_num].flag == false&&flag==false) {
			
			sch[sch_num].flag = true;
			sch[sch_num].stu_num++;
			sch[sch_num].tws += score;
			sch_num++;
		}
			
	
		
	}
	sort(sch, sch + sch_num, cmp);
	for (int i = 0; i < sch_num; i++) {
		if (i != 0) {
			if (sch[i].tws == sch[i - 1].tws) {
				sch[i].binglie = sch[i - 1].binglie + 1;
			}
		}
		sch[i].rank = i + 1 - sch[i].binglie;
	}
	printf("%d\n", sch_num);
	for (int i = 0; i < sch_num; i++) {
		printf("%d %s %d %d\n", sch[i].rank, sch[i].name, sch[i].tws, sch[i].stu_num);
	}
	return 0;

}
