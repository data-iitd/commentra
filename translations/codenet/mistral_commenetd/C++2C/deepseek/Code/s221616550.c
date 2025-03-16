#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a given string is a palindrome
bool isPalindrome(char* s){
  // Iterate through the first half of the string
  for(int i=0; i<strlen(s)/2; i++){
    // Check if the character at current index is same as its mirror index
    if(s[i]==s[strlen(s)-1-i]){
      // If yes, continue to next character
      continue;
    }else{
      // If no, return false as the string is not a palindrome
      return false;
    }
  }
  // If we reach here, it means all characters in the first half are same as their mirror index
  // So, the string is a palindrome
  return true;
}

int main(){
  // Declare a character array to store user input
  char s[100];
  // Take user input and store it in the character array
  scanf("%s", s);
  // Check if the given string is a palindrome and its first half is also a palindrome
  if(isPalindrome(s) && isPalindrome(strncpy(s, s, strlen(s)/2))){
    // If yes, print "Yes"
    printf("Yes\n");
  }else{
    // If no, print "No"
    printf("No\n");
  }
  // Return 0 to indicate successful execution of the program
  return 0;
}
