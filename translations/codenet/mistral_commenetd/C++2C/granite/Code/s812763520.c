
#include <stdio.h>
#include <string.h> // We include the string library to use functions like'strcmp' in C STL

int main(){
  int n; // We declare an integer variable 'n' to store the number of elements in the strings
  char a[1000], b[1000], c[1000]; // We declare three character arrays 'a', 'b', and 'c' to store the input strings
  int ans = 0; // We initialize an integer variable 'ans' to 0 to store the answer

  scanf("%d", &n); // We read the number of elements in the strings from the standard input
  scanf("%s %s %s", a, b, c); // We read the three strings 'a', 'b', and 'c' from the standard input, one string at a time

  for(int i = 0; i < n; i++){ // We start a for loop that iterates from 0 to 'n'-1
    if(a[i] == b[i] && b[i] == c[i]){ // We check if all three characters at the current index are equal
    }else if(strcmp(a+i, b+i) == 0 || strcmp(b+i, c+i) == 0 || strcmp(a+i, c+i) == 0){ // We check if any two of the three characters are equal
      ans++; // If so, we increment the answer by 1
    }else{ // If none of the above conditions are met, we increment the answer by 2
      ans += 2;
    }
  }
  printf("%d\n", ans); // We print the answer to the standard output
}
