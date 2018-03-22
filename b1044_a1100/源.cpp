#include<map>
#include<cstdio>	
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
string number1[13] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string number2[13] = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
map<string, int> strToNum;
string numToStr[170];
void init() {
	for (int i = 0; i < 13; i++) {
		numToStr[i] = number1[i];
		strToNum[number1[i]] = i;
		numToStr[i * 13] = number2[i];
		strToNum[number2[i]] = i * 13;
	}
	for (int i = 1; i < 13; i++) {
		for (int j = 1; j < 13; j++)
		{
			string str = number2[i] +" "+ number1[j];
			numToStr[i * 13 + j] = str;
			strToNum[str] = i * 13 + j;
		}
	}
}
int main() {
	init();
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n;i++) {
		string str;
		getline(cin, str);
		if (str[0] >= '0'&&str[0] <= '9') {
			int num = 0;
			for (int i = 0; i < str.length(); i++) {
				num = num * 10 + str[i] - '0';
			}
			cout << numToStr[num] << endl;
		}
		else
		{
			cout << strToNum[str] << endl;
		}
	}
	return 0;
}