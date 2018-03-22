#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>	
#include<string>
#include<cstring>
using namespace std;
const double eps = 1e-8;
struct School
{
	char name[10];
	double tws;
	int num;
	int twsInt;
	School(char* a, double b, int c, int d) :tws(b), num(c), twsInt(d) { strcpy(name, a); }

	bool operator <(School s) {
		if (twsInt == s.twsInt) {
			if (num == s.num) {
				return strcmp(name, s.name) < 0;
			}
			else
			{
				return num < s.num;
			}
		}
		else
		{
			return twsInt > s.twsInt;
		}
	}
};
/*bool cmp(School a, School b) {
	if (a.tws == b.tws) {
		if (a.num == b.num) {
			return strcmp(a.name, b.name) < 0;
		}
		else
		{
			return a.num < b.num;
		}
	}
	else
	{
		return a.tws > b.tws;
	}
}*/
int main(){
	int n;
	scanf("%d", &n);
	double score;

	int m;
	char id[10], name[10];
	vector<School> sch;
	string str;
	map<string, int> mp;
	while (n--) {
		scanf("%s %lf %s", id, &score, name);
		if (id[0] == 'B')score /= 1.5;
		if (id[0] == 'T')score *= 1.5;
		for (int i = 0; i < strlen(name); i++) {
			if (name[i] >= 'A'&&name[i] <= 'Z')name[i] += 32;
		}
		str = name;
		if (mp.find(str) == mp.end()) {//新学校；
			mp[str] = sch.size();
			sch.push_back(School(name, score, 1,int(score+eps)));//初始化
		}
		else
		{
			m = mp[str];
			sch[m].num++;
			sch[m].tws += score;
			sch[m].twsInt = int(sch[m].tws + eps);
		}
	}
	sort(sch.begin(), sch.end());
	printf("%d\n", sch.size());
	int k = 0;
	int grade;
	while (k < sch.size()) {
		int rank = k + 1;
		grade = sch[k].twsInt;
		while (k<sch.size()&&sch[k].twsInt==grade)
		{
			printf("%d %s %d %d\n", rank, sch[k].name, sch[k].twsInt, sch[k].num);
			k++;
		}
	}
	return 0;
}