#include <iostream>
#include <cmath>
#include <queue>
#include <random>
#include <limits>

using namespace std;

int main() {
  long long N;
  cin >> N;

  long long min = 0;
  for (int i = 0; i < 5; i++) {
    long long temp;
    cin >> temp;
    if (i == 0) {
      min = temp;
    } else {
      min = std::min(min, temp);
    }
  }

  long long ans = (long long)std::ceil((double)N / min) + 4;
  cout << ans << endl;

  return 0;
}
