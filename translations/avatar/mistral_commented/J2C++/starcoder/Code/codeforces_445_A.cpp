
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // Read input from the standard input stream using a cin object
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;

  // Create an array ans of size n to store the processed strings
  vector<string> ans(n);

  // Iterate through each string in the input
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    string temp = "";

    // Iterate through each character in the string
    for (int j = 0; j < m; j++) {
      if (str[j] == '-') {
        temp += "-";
      } else {
        if ((i + j) % 2 == 1) {
          temp += "W";
        } else {
          temp += "B";
        }
      }
    }

    // Store the final string in the ans array using the index i
    ans[i] = temp;
  }

  // Iterate through each string in the ans array and print it to the standard output stream
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}

