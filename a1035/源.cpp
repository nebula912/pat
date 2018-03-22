#include<cstdio>
#include<cstring>
#include<string>
struct user
{
	char name[12];
	char password[12];
};
int main() {
	int n, m=0;
	user in;
	user ans[1010];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		bool flag = true;
		scanf("%s %s", in.name, in.password);
		for (int j = 0; j < strlen(in.password); j++) {
			if (in.password[j] == '1') {
				flag = false;
				in.password[j] = '@';
			}
			else
			{
				if (in.password[j] == '0') {
					flag = false;
					in.password[j] = '%';
				}
				else
				{
					if (in.password[j] == 'l') {
						flag = false;
						in.password[j] = 'L';
					}
					else
					{
						if (in.password[j] == 'O') {
							flag = false;
							in.password[j] = 'o';
						}
					}
				}
			}
			
		}
		if (flag == false) {
			ans[m++] = in;
		}

	}
	if (m == 0) {
		if (n != 1) {
			printf("There are %d accounts and no account is modified", n);
		}
		else
		{
			printf("There is 1 account and no account is modified");
		}
	}
	else
	{
		printf("%d\n", m);
		for (int i = 0; i < m; i++) {
			printf("%s %s\n", ans[i].name, ans[i].password);
		}
	}
	return 0;

}