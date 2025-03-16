
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  if (n == 1) {
    cout << "Hello World" << endl;
  } else {
    string strs[2];
    cin >> strs[0] >> strs[1];
    int num1 = stoi(strs[0]);
    int num2 = stoi(strs[1]);
    cout << num1 + num2 << endl;
  }

  return 0;
}

