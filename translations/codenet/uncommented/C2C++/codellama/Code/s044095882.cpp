#include <iostream>

int main()
{
  long int n;

  std::cin >> n;
  long int a[n];
  long int count[n];

  for (long int i = 1; i < n; i++)
    std::cin >> a[i];

  for (long int i = 0; i < n; i++)
    count[i] = 0;

  for (long int i = 1; i < n; i++)
    count[a[i]-1]++;

  for (long int i = 0; i < n; i++)
    std::cout << count[i] << std::endl;

  return 0;
}

