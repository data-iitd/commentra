
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

int main() {
int n;
cin >> n;
cout << n << endl;
int m = n;
for (int i = n - 1; i > 0; i--) {
if (m % i == 0) {
cout << i << endl;
m = i;
}
}
return 0;
}
// END-OF-CODE


