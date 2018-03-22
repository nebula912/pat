#include<stdio.h>
char map[3]={'W','T','L'};
int main() {
	float profit=1.0;
    float temp;
	int result;
	for (int i = 0; i < 3; i++) {
        float max = 0.0;
		for (int j = 0; j < 3; j++) {
			scanf("%f", &temp);
			
			if (temp > max) { max = temp; result = j; }
		}
		profit *= max;
		printf("%c ", map[result]);
	}
		printf("%.2f", (profit*0.65 - 1.0) * 2);
	return 0;

}