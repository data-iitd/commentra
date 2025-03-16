
#include <bits/stdc++.h>
using namespace std;

int main() {
int N;
cin >> N;
unordered_map <int, string> map;
for (int i = 0; i < N; i++) {
string s;
cin >> s;
map[i] = s;
}
bool ans = true;
unordered_map <string, int> past;
string next = "";
for (int i = 0; i < N; i++) {
if (past.count(map[i]) > 0) {
ans = false;
break;
}
past[map[i]] = i;
if (i!= 0) {
if (next!= map[i].substr(0, 1)) {
ans = false;
break;
}
}
next = map[i].substr(map[i].length() - 1, map[i].length());
}
if (ans) {
cout << "Yes" << endl;
} else {
cout << "No" << endl;
}
return 0;
}
//END-OF-CODE