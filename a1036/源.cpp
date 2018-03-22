#include<cstdio>

struct studentinfo
{
	char gender;
	char id[12];
	char name[12];
	int grade;
	
}temp, min_m, max_f;
int main() {
	int n;
	int numf=0, numm = 0;
	min_m.grade = 101;
	max_f.grade = -1;
	scanf("%d", &n);
	int disdinct=101;
	for (int i = 0; i < n; i++) {
		scanf("%s %c %s %d", temp.name, &temp.gender, temp.id, &temp.grade);
		if (temp.gender == 'M') {
			numm++;
			if (temp.grade < min_m.grade)min_m = temp;

		}
		else
		{
			numf++;
			if (temp.grade > max_f.grade)max_f = temp;
		}
	}
	disdinct = max_f.grade - min_m.grade;
	if (numf != 0) {
		printf("%s %s\n", max_f.name, max_f.id);
	}
	else
	{
		printf("Absent\n");
	}
	if (numm != 0) {
		printf("%s %s\n", min_m.name, min_m.id);
	}
	else
	{
		printf("Absent\n");
	}
	if(numf==0||numm==0)
	{
		printf("NA");
	}
	else
	{
		printf("%d", disdinct);
	}
	return 0;
}