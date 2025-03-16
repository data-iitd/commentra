#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  string str1, str2;
  cin >> str1 >> str2;

  sort(str1.begin(), str1.end());
  sort(str2.rbegin(), str2.rend());

  int loop = str1.length() > str2.length() ? str2.length() : str1.length();
  bool flag = False;

  for i in range(loop):
    ch1 = str1[i];
    ch2 = str2[i];

    if ch1 == ch2:
      if loop == i + 1 and str1.length() < str2.length():
        flag = True;
        break;
      else:
        continue;
    else:
      if ch2 > ch1:
        flag = True;
        break;
      else:
        break;

  if flag:
    print("Yes")
  else:
    print("No")
}

