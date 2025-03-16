#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
  int i_min, min;
  int i, j, k;
  int X, N;
  std::cin >> X >> N;
  if (N == 0) {
    std::cout << X << std::endl;
    return 0;
  }

  std::vector<int> plus(256, 0);
  std::vector<int> minus(256, 0);

  for (i = 0; i < 256; i++) {
    plus[i] = i;
    minus[i] = -i;
  }

  for (i = 0; i < N; i++) {
    std::cin >> j;
    plus[j] = 0;
  }

  i_min = 0;
  min = 1000;
  for (i = 255; i >= 0; i--) {
    if (plus[i] == 0 && i > 0) {
      continue;
    }
    k = X - plus[i];
    if (k < 0) { k *= -1; }
    if (k <= min) {
      min = k;
      i_min = i;
    }
  }

  std::cout << i_min << std::endl;

  return 0;
}

