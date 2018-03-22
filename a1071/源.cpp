#include<map>
#include<iostream>
#include<string>
using namespace std;
bool check(char c) {
	if (c <= '9'&&c >= '0')return true;
	if (c >= 'a'&&c <= 'z')return true;
	if (c >= 'A'&&c <= 'Z')return true;
	return false;
}
int main() {
	map<string, int> count;
	string str;
	getline(cin, str);
	int i = 0;
	while (i<str.length())
	{
		string word;
		while (i < str.length() && check(str[i])) {
			if (str[i] >= 'A'&&str[i] <= 'Z') {
				str[i] += 32;
			}
			word += str[i];
			i++;
		}
		if (word != "") {
			if (count.find(word) != count.end()) {
				count[word]++;
			}
			else
			{
				count[word] = 1;
			}
		}
		while (i < str.length()&&check(str[i])==false)
		{
			i++;
		}
	}
	string ans;
	int max;
	for (map<string, int>::iterator it = count.begin(); it != count.end(); it++) {
		if (it->second > max) {
			max = it->second;
			ans = it->first;
		}
	}
	cout << ans << " " << max << endl;
	return 0;
}