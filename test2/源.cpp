#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 41;
string str[maxn];
int main() {
	int n;
	char D;
	scanf("%c %d", &D, &n);
	str[0] += D;
	for(int i=0;i<n;i++){
		int step = 0;
		for (int k = 0; k < str[i].length(); k++) {
			char c = str[i][k];
			if (step == 0) str[i + 1] += c;
			int p = k;
			while(str[i][p++]==c){
				step++;
			}
			if (step != 0) {
				c = step + '0';
				str[i + 1] += c;
				step = 0;
			}
			k = p - 2;
		}
	}
	 cout << str[n - 1] << endl; 
	return 0;
}