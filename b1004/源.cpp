#include<cstdio>
struct student
{
	char name[15];
	char id[15];
	int score;
}temp,max_student,min_student;
int main() {
	int N;
	scanf("%d", &N);
	max_student.score = -1;
	min_student.score = 101;
	for (int i = 0; i < N; i++) {
		scanf("%s %s %d", temp.name, temp.id, &temp.score);
		if (temp.score > max_student.score)max_student = temp;
		if (temp.score < min_student.score)min_student = temp;
	}
	printf("%s %s\n", max_student.name, max_student.id);
	printf("%s %s\n", min_student.name, min_student.id);
	return 0;
}