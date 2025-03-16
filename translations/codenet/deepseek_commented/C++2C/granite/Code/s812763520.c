
#include <stdio.h>

int main(){
  int n, ans = 0; // Declare integer n and initialize ans to 0
  char a[100], b[100], c[100]; // Declare three character arrays a, b, and c
  scanf("%d", &n); // Read the integer n from standard input
  scanf("%s %s %s", a, b, c); // Read the three character arrays a, b, and c from standard input
  
  // Loop through each character position up to n
  for(int i = 0; i < n; i++){
    // Check if all three characters at position i are the same
    if(a[i] == b[i] && b[i] == c[i]){
      // Do nothing
    }
    // Check if any two characters at position i are the same
    else if(a[i] == b[i] || b[i] == c[i] || a[i] == c[i]){
      ans++; // Increment ans by 1
    }
    // If all three characters at position i are different
    else{
      ans += 2; // Increment ans by 2
    }
  }
  printf("%d\n", ans); // Print the final value of ans
}
