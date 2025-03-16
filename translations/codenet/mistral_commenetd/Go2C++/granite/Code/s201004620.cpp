
// C++ code to translate the given Go code

#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;

  if (S == "Sunny") {
    cout << "Cloudy" << endl;
  } else if (S == "Cloudy") {
    cout << "Rainy" << endl;
  } else if (S == "Rainy") {
    cout << "Sunny" << endl;
  }

  return 0;
}

// End of the code