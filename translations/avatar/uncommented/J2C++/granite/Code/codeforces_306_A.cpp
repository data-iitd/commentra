
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
int n, m;
cin >> n >> m;
vector<int> a(m, n / m);
int sub = n / m;
int test = n - (sub * m);
int count = 0;
for (int i = 0; i < test; i++) {
a[count] = a[count] + 1;
count++;
if (count > a.size()) count = 0;
}
reverse(a.begin(), a.end());
for (int i = 0; i < a.size(); i++) {
cout << a[i] << " ";
}
return 0;
}

