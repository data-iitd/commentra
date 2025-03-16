
#include <bits/stdc++.h>

using namespace std;

int main() {

  // Initialize input and output streams
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // Read input integers a, b, c, and d
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  // Check if c is greater than b
  if (c > b) {
    // If yes, print 0 and exit
    cout << 0 << endl;
    return 0;
  }

  // Check if a is greater than d
  else if (a > d) {
    // If yes, print 0 and exit
    cout << 0 << endl;
    return 0;
  }

  // Check if a is less than c
  else if (a < c) {
    // If yes, calculate the difference between the smaller and larger of b and d
    int difference = min(b, d) - c;
    // Print the difference
    cout << difference << endl;
    return 0;
  }

  // If none of the above conditions are true, then a, b, c, and d are in sorted order
  else {
    // Create a List of integers a, b, c, and d
    list<int> l;
    l.push_back(a);
    l.push_back(b);
    l.push_back(c);
    l.push_back(d);

    // Sort the List in ascending order
    l.sort();

    // Calculate the difference between the second and third elements of the List
    int difference = l.front() - l.back();

    // Print the difference
    cout << difference << endl;
  }
}

