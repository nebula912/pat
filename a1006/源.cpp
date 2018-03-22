#include<cstdio>
struct time
{
	char id[20];
	int hh;
	int mm;
	int ss;
};
bool earlier(time a, time b) {
	if (a.hh != b.hh)return a.hh <= b.hh;
	else
	{
		if (a.mm != b.mm)return a.mm <= b.mm;
		else
		{
			return a.ss <= b.ss;
		}
	}
}
bool more(time a, time b) {
	if (a.hh != b.hh)return a.hh >= b.hh;
	else
	{
		if (a.mm != b.mm)return a.mm >= b.mm;
		else
		{
			return a.ss >= b.ss;
		}
	}
}
int main() {
	int m;
	scanf("%d", &m);
	time tem,in,out;
	
	out.hh = 0, out.mm = 0, out.ss = 0;
	in.hh = 24, in.mm = 60, in.ss = 60;
	for (int i = 0; i < m; i++) {
		scanf("%s %d:%d:%d", tem.id, &tem.hh, &tem.mm, &tem.ss);
		if (earlier(tem, in))in = tem;
		
		scanf("%d:%d:%d",  &tem.hh, &tem.mm, &tem.ss);
		if (more(tem, out))out =tem;

	}
	printf("%s %s", in.id, out.id);
	return 0;
}