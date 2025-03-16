#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  string str1, str2;
  cin >> str1 >> str2;

  // Sort the first string in ascending order
  sort(str1.begin(), str1.end());

  // Sort the second string in descending order
  sort(str2.rbegin(), str2.rend());

  // Determine the loop limit based on the length of the shorter string
  int loop = str1.length() > str2.length() ? str2.length() : str1.length();
  bool flag = false;

  // Compare characters of the two sorted strings
  for(int i = 0; loop > i; i++){
    char ch1 = str1[i];
    char ch2 = str2[i];

    // If characters match, continue to the next character
    if(ch1 == ch2){
      if(loop == i + 1 && str1.length() < str2.length()){
        flag = true;
        break;
      }else{
        continue;
      }
    }else{
      // If characters do not match, check if the character from the second string is greater
      if(ch2 > ch1){
        flag = true;
        break;
      }else{
        break;
      }
    }
  }

  // Check the flag and print the result
  if(flag){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}