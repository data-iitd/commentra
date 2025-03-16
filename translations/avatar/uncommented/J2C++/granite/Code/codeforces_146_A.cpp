
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
int x = 0, y = 0, t = 0, n;
string str;
cin >> n >> str;
char l[n];
for (int i = 0; i < n; i++) {
if (str[i]!= '4' && str[i]!= '7') {
t = 1;
}
}
if (t == 1) {
cout << "NO" << endl;
} else {
for (int i = 0; i < n / 2; i++) {
x = x + (str[i] - '0');
}
for (int i = n - 1; i > (n / 2) - 1; i--) {
y = y + (str[i] - '0');
}
if (x == y) {
cout << "YES" << endl;
} else {
cout << "NO" << endl;
}
}
return 0;
}
//END-OF-CODE