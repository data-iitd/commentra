

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
 int n;
 cin >> n;
 vector<int> a(n), b(n);
 for (int i = 0; i < n; i++) {
 cin >> a[i] >> b[i];
 }
 int max_a = *max_element(a.begin(), a.end());
 int min_b = *min_element(b.begin(), b.end());
 bool flag = false;
 for (int i = 0; i < n; i++) {
 if (a[i] > max_a && b[i] < min_b) {
 flag = true;
 break;
 }
 }
 if (flag) {
 cout << "Happy Alex" << endl;
 } else {
 cout << "Poor Alex" << endl;
 }
 return 0;
}

