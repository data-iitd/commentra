
#include <bits/stdc++.h>

using namespace std;

int main() {
  // Reading the first long integer input N
  long long N = 0;
  cin >> N;

  // Initializing the minimum long integer variable with the first input value
  long long min = 0;
  for (int i = 0; i < 5; i++) {
    if (i == 0) { // If it's the first iteration of the loop
      cin >> min; // Set the minimum value to the current input value
    } else { // Otherwise
      min = min < cin? min : cin; // Update the minimum value with the current input value if it's smaller
    }
  }

  // Printing the answer using the p method
  p((long long)ceil((double)N/min)+4);
}

// Utility method to print a string as output
void p(string ans) {
  cout << ans << endl;
}

// Utility method to print an integer as output
void p(int ans) {
  cout << ans << endl;
}

// Utility method to print nothing as output
void p() {
  cout << endl;
}

// Utility method to print a long integer as output
void p(long long ans) {
  cout << ans << endl;
}

// Utility method to print a double as output
void p(double ans) {
  cout << ans << endl;
}

