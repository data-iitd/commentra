#include <iostream>

int main(void)
{
  char s[4], t[4];
  std::cin >> s;
  std::cin >> t;
  int hit = 0;
  for (int i = 0; i < 3; i++){
    if (s[i] == t[i]) hit++;
  }
  std::cout << hit << std::endl;
  return 0;
}

