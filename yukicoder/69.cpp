#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	printf("%s\n", a==b ? "YES" : "NO");
}
