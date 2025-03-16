
#include <iostream>
using namespace std;

int main() {
  int i, N, x;
  x = 0;

  cout << "Enter a number: ";
  cin >> N;

  for(i=1; i<=N; i++){
    x += i;
  }

  cout << "The sum of numbers from 1 to " << N << " is: " << x << endl;

  return 0;
}

