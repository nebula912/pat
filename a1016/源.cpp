#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
struct record
{
	char name[21];
	int mm, dd, hh, min;
	bool online;//true for online, false for offline

}rec[1005],temp;
int toll[25];
bool cmp(record a, record b) {
	int s = strcmp(a.name, b.name);
	if (s!=0) return s < 0;
	else if (a.mm != b.mm) return a.mm < b.mm;
	else if (a.dd != b.dd) return a.dd < b.dd;
	else if (a.hh != b.hh)return a.hh < b.hh;
	else return a.min < b.min;
}
void get_ans(int on, int off, int& time, int& money) {
	temp = rec[on];
	while (temp.dd < rec[off].dd||temp.hh<rec[off].hh||temp.min<rec[off].min) {
		time++;
		money += toll[temp.hh];
		temp.min++;
		if (temp.min >= 60) { temp.min = 0;
		temp.hh++;
		}
		if (temp.hh >= 24) {
			temp.hh = 0;
			temp.dd++;
		}
	}
}
int main() {
	int n;
	
	for (int i = 0; i < 24; i++) {
		scanf("%d", &toll[i]);
	}
	scanf("%d", &n);
	int num = 0;
	char line[10];
	for (int i = 0; i < n; i++) {
		scanf("%s %d:%d:%d:%d %s", rec[i].name, &rec[i].mm, &rec[i].dd, &rec[i].hh, &rec[i].min, line);
		if (strcmp(line, "on-line") == 0) {
			rec[i].online = true;
		}
		else
		{
			rec[i].online = false;
		}
	}
		sort(rec, rec + n, cmp);
		int on = 0, off, next;
		while (on < n) {
			int flag = 0;
			next = on;
			while (next<n&&strcmp(rec[next].name,rec[on].name)==0)
			{
				if (flag == 0 && rec[next].online == true) {
					flag = 1;
				}
				else if (flag == 1 && rec[next].online == false) {
					flag = 2;
				}
				next++;
			}
			if (flag < 2) {
				on = next;
				continue;
			}
			int total = 0;
			printf("%s %02d\n", rec[on].name, rec[on].mm);
			while (on<next)
			{
				while (on < next - 1 && !(rec[on].online == true && rec[on + 1].online == false)) {
					on++;
				}
				off = on + 1;
				if (off == next) {
					on = next;
					break;
				}
				printf("%02d:%02d:%02d ", rec[on].dd, rec[on].hh, rec[on].min);
				printf("%02d:%02d:%02d ", rec[off].dd, rec[off].hh, rec[off].min);
				int time = 0, money = 0;
				get_ans(on, off, time, money);
				total += money;
				printf("%d $%.2f\n", time, money / 100.0);
				on = off + 1;
			}
			printf("Total amount: $%.2f\n", total/100.0);
		}
		
		
	
	
	return 0;
}