#include<string>
#include<cstdio>
#include<iostream>
using namespace std;
long long  findDpart(long long a,int da) {
	long long pa = 0;
	while (a!=0 ) {
		if (a % 10 == da)pa =pa*10+ da;
		a /= 10;
	}
	return pa;
};
int main() {
	int  da, db;
	long long a, b;
	scanf("%lld%d%lld%d", &a, &da, &b, &db);
	long long  pa = 0, pb = 0;
	pa = findDpart(a, da);
	pb = findDpart(b, db);
	printf("%lld", pa + pb);
	return 0;
}