#include <iostream>

using namespace std;

int main(void)
{
  char s[4], t[4];
  cin >> s;
  cin >> t;
  int hit = 0;
  for (int i = 0; i < 3; i++){
    if (s[i] == t[i]) hit++;
  }
  cout << hit << endl;
  return 0;
}
