#include <iostream>

using namespace std;

int main(void)
{
  long int n;

  cin >> n;
  long int a[n];
  long int count[n];

  for (long int i = 1; i < n; i++)
    cin >> a[i];

  for (long int i = 0; i < n; i++)
    count[i] = 0;

  for (long int i = 1; i < n; i++)
    count[a[i]-1]++;

  for (long int i = 0; i < n; i++)
    cout << count[i] << endl;

  return 0;
}
