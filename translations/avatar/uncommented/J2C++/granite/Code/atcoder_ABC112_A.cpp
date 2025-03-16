
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
int n;
cin >> n;
if (n == 1) {
cout << "Hello World" << endl;
} else {
string s1, s2;
cin >> s1 >> s2;
stringstream ss;
ss << s1 << s2;
int sum;
ss >> sum;
cout << sum << endl;
}
return 0;
}

// 