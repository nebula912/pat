#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct record
{
	int id;
	char name[10];
	int grade;
}Rec[100005],temp;
bool cmp1(record a, record b) {
	if (a.id != b.id)return a.id < b.id;
}
bool cmp2(record a,record b) {
	int s = strcmp(a.name, b.name);
	if(s!=0)return s < 0;
	else
	{
		return a.id < b.id;
	}
}
bool cmp3(record a,record b) {
	if(a.grade!=b.grade)return a.grade < b.grade;
	else
	{
		return a.id < b.id;
	}
}
int main() {
	int N, C;
	scanf("%d%d", &N, &C);
	for (int i = 0; i < N; i++) {
		scanf("%d %s %d", &Rec[i].id, Rec[i].name, &Rec[i].grade);

	}
	switch (C)
	{
	case 1: sort(Rec, Rec + N, cmp1);
		break;
	case 2: sort(Rec, Rec + N, cmp2);
		break;
	case 3:sort(Rec, Rec + N, cmp3);
		break;
	}
	for (int i = 0; i < N; i++) {
		printf("%06d %s %d\n", Rec[i].id, Rec[i].name, Rec[i].grade);
	}
	return 0;
}