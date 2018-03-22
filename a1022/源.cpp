#include<map>
#include<string>
#include<iostream>
#include<algorithm>
#include<set>
#include<cstdio>
using namespace std;
map<string, set<int> > mpTitle, mpAuthor, mpKey, mpPub, mpYear;
void query(map<string, set<int> >&mp, string &str) {
	if (mp.find(str) == mp.end())printf("Not Found\n");
	else
	{
		for (set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++) {
			printf("%07d\n", *it);
		}
	}
}
int main() {
	int n;
	int m, id, type;
	char c;
	string title, author, key, pub, year;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &id);
		 c = getchar();
		getline(cin, title);
		mpTitle[title].insert(id);
		getline(cin, author);
		mpAuthor[author].insert(id);
		while (cin >> key) {
			mpKey[key].insert(id);
			c = getchar();
			if (c == '\n')break;
		}
		getline(cin, pub);
		mpPub[pub].insert(id);
		getline(cin, year);
		mpYear[year].insert(id);
	
	}
	string temp;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d: ", &type);
		getline(cin, temp);
		cout << type << ": " << temp << endl;
		switch (type)
		{
		case 1:query(mpTitle, temp); break;
		case 2:query(mpAuthor, temp); break;
		case 3:query(mpKey, temp); break;
		case 4:query(mpPub, temp); break;
		case 5:query(mpYear, temp); break;
		}
	}
	return 0;
}