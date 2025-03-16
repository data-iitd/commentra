#include <stdio.h>
#include <string.h>

// Function to check if a given string is a palindrome
int isPalindrome(char s[]){
  // Loop through the first half of the string
  for(int i=0; i<strlen(s)/2; i++){
    // Compare characters from the start and end of the string
    if(s[i] == s[strlen(s)-1-i]) 
      continue; // If they match, continue to the next iteration
    else 
      return 0; // If they don't match, return false
  }
  return 1; // If all characters matched, return true
}

int main(){
  char s[100]; // Declare a string variable to hold user input
  scanf("%s", s); // Read input from the user

  // Check if the entire string is a palindrome and if the first half is also a palindrome
  if(isPalindrome(s) && isPalindrome(s) + strlen(s)/2){
    printf("Yes\n"); // Output "Yes" if both conditions are true
  } else {
    printf("No\n"); // Output "No" if either condition is false
  }
  
  return 0; // Return 0 to indicate successful execution
}

