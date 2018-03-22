#include<stdio.h>
struct student
{
	int school;
	int score;
}temp;
int school[100010] = {0};
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &temp.school, &temp.score);
		school[temp.school] += temp.score;
	}
	int max = -1, num = 0;;
	for (int i = 1; i <= n; i++) {
		if (school[i] > max) {
			max = school[i]; 
			num = i;
		}
	}
	printf("%d %d", num, max);
	return 0;
}