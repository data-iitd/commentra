#include <iostream>
#include <algorithm> // We include the algorithm library to use functions like 'next_permutation' in C++ STL
using namespace std; // We use the standard namespace to avoid writing 'std::' before every standard library function and object

int main(){
  int n; // We declare an integer variable 'n' to store the number of elements in the strings
  string a, b, c; // We declare three string variables 'a', 'b', and 'c' to store the input strings
  int ans = 0; // We initialize an integer variable 'ans' to 0 to store the answer

  cin >> n; // We read the number of elements in the strings from the standard input
  cin >> a >> b >> c; // We read the three strings 'a', 'b', and 'c' from the standard input, one string at a time

  for(int i = 0; i < n; i++){ // We start a for loop that iterates from 0 to 'n'-1
    if(a[i] == b[i] and b[i] == c[i]): // We check if all three characters at the current index are equal
      pass
    elif(a[i] == b[i] or b[i] == c[i] or a[i] == c[i]): // We check if any two of the three characters are equal
      ans += 1
    else: // If none of the above conditions are met, we increment the answer by 2
      ans += 2
  }
  print(ans) // We print the answer to the standard output
}


