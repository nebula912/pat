#include<cstdio>
#include<string>
#include<cstring>
char day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
char code[5][85];
int main() {
	for (int i = 0; i < 4; i++) {
		scanf("%s", code[i]);
	}
	int day1;
	int hour=0;
	int min;
	int flag = 0;
	int count = 0;
	for (int i = 0; i <  i < strlen(code[0]) && i<strlen(code[1]); i++) {
		char temp = code[0][i];
		if ( temp<= 'Z'&&temp >= 'A') {
			

			if (temp == code[1][i]) {
				if (temp <= 'G'&&temp >= 'A'&&flag==0) 	  
				{
					day1 = temp - 'A';
					 flag=1;
				}
				 if(temp>='A'&&temp<='N'&&flag==1)
				{
					hour = temp - 'A'+10;
				}
			}

		}
		else
		{
			if (temp <= '9'&&temp >= '0'&&flag == 1) {
				if (temp == code[1][i]) {
					hour = temp - '0';
				}
			}
			else
			{
				continue;
			}
		}
	}
	for (int i = 0; i < strlen(code[3])&&i<strlen(code[2]); i++) {
		char temp = code[2][i];
			if ((temp >= 'a'&&temp <= 'z') || (temp >= 'A'&&temp <= 'Z')) {
			     if (temp == code[3][i]) {
					 min = i;
					 break;
			}
		}
	}
	printf("%s %02d:%02d", day[day1], hour, min);
	return 0;
}