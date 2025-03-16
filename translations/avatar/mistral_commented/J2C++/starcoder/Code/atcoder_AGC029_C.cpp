
#include <bits/stdc++.h>

using namespace std;

class Main {

public:

int n;
int a[100000];
map<int, int> s;

void set() {
try {
cin >> n;
for (int i = 0; i < n; i++) cin >> a[i];
} catch (exception &e) {
cout << e.what() << endl;
}
}

void solve() {
set();
int ng = 0, ok = n;

while (ok - ng > 1) {
int k = (ng + ok) / 2;
if (isPossible(k)) ok = k;
else ng = k;
}

cout << ok << endl;
}

bool isPossible(int k) {
s.clear();
int current = 0;

for (int i = 0; i < n; i++) {
if (a[i] <= current) {
if (k == 1) return false;

while (!s.empty() && s.rbegin()->first >= a[i]) {
s.erase(s.rbegin()->first);
}

int p = a[i] - 1;
while (true) {
if (p < 0) return false;

int sp = s[p] + 1;
s[p] = sp;

if (sp == k) {
s.erase(p);
p--;
} else {
break;
}
}
}
current = a[i];
}

return true;
}
};

