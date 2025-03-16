#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  string str1, str2;
  cin >> str1 >> str2;

  # Sort the first string in ascending order
  str1.sort()

  # Sort the second string in descending order
  str2.sort(reverse=True)

  # Determine the loop limit based on the length of the shorter string
  loop = str1.length() > str2.length() ? str2.length() : str1.length()
  flag = False

  # Compare characters of the two sorted strings
  for i in range(loop):
    ch1 = str1[i]
    ch2 = str2[i]

    # If characters match, continue to the next character
    if ch1 == ch2:
      if loop == i + 1 and str1.length() < str2.length():
        flag = True
        break
      else:
        continue
    else:
      # If characters do not match, check if the character from the second string is greater
      if ch2 > ch1:
        flag = True
        break
      else:
        break

  # Check the flag and print the result
  if flag:
    print("Yes")
  else:
    print("No")
}

