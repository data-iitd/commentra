
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
  // Step 1: Reading Input
  int X, N;
  cin >> X >> N;
  
  // If no values are excluded, print X and exit
  if (N == 0) {
    cout << X << endl;
    exit(0);
  }
  
  // Step 2: Initializing Arrays
  int plus[256];
  int minus[256];
  for (int i = 0; i < 256; i++) {
    plus[i] = i;
    minus[i] = -i;
  }
  
  // Step 3: Marking Excluded Values
  for (int i = 0; i < N; i++) {
    int j;
    cin >> j;
    plus[j] = 0;
  }
  
  // Step 4: Finding the Nearest Non-Zero Value
  int i_min = 0;
  int min = 1000;
  for (int i = 255; i >= 0; i--) {
    if (plus[i] == 0 && i > 0) {
      continue;
    }
    int k = X - plus[i];
    if (k < 0) { k *= -1; }
    if (k <= min) {
      min = k;
      i_min = i;
    }
  }
  
  // Step 5: Outputting the Result
  cout << i_min << endl;
  
  return 0;
}


