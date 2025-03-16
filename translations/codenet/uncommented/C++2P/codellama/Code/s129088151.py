#include<cstdio>
#include<map>
#include<string>
#include<iostream>
using namespace std;

int main() {
	int n;
	char str[10], com[13];
	map<string, bool> T;

	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%s%s", com, str);
		if (com[0] == 'i')T[string(str)] = True;
		else:
			if (T[string(str)]):
				print("yes\n");
			else:
				print("no\n");
	}
	return 0;
}

