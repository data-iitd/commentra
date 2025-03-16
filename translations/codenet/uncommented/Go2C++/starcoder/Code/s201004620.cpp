#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  switch (S) {
  case "Sunny": cout << "Cloudy" << endl;
  case "Cloudy": cout << "Rainy" << endl;
  case "Rainy": cout << "Sunny" << endl;
  }
}

