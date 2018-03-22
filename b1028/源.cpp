#include<cstdio>
struct person
{
	char name[6];
	int year;
	int month;
	int day;
}people;
bool less(person a, person b) {
	if (a.year != b.year)  return a.year <= b.year; 
	else
	{
		if (a.month != b.month)return a.month <= b.month;
		else
		{
			return a.day <= b.day;
		}
	}
}
bool more(person a, person b) {
	if (a.year != b.year)  return a.year >= b.year;
	else
	{
		if (a.month != b.month)return a.month >= b.month;
		else
		{
			return a.day >= b.day;
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	person temp,old, young;
	
	int count = 0;
	person today, edge;
	today.year =old.year= 2014;
	today.month =old.month= 9;
	today.day = old.day=6;
	young.year = edge.year = 1814;
	young.month = edge.month = 9;
	young.day = edge.day = 6;
	for (int i = 0; i < n; i++) {
		scanf("%s %d/%d/%d", temp.name, &temp.year, &temp.month, &temp.day);
		if (less(temp, today) && more(temp, edge)) {
			count++;
			if (less(temp, old))old = temp;
			if (more(temp, young))young = temp;
		}
	}
	if (count == 0)printf("0");
	else
	{
		printf("%d %s %s", count, old.name, young.name);
	}
	return 0;
}