
#include <bits/stdc++.h>
using namespace std;

class BABC {
public:
void solve(std::cin, std::cout) {
string s;
cin >> s;
long long cnt = 0, tmp = 0;
for (int i = 0; i < s.size(); i++) {
if (s[i] == 'A') {
tmp++;
} else if (s[i] == 'D') {
cnt += tmp;
} else {
tmp = 0;
}
}
cout << cnt << endl;
}
};

int main() {
BABC solver;
solver.solve(std::cin, std::cout);
return 0;
}
// END-OF-CODE