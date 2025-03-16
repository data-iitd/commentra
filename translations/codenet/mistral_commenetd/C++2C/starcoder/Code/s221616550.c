#include <stdio.h>
#include <string.h>

// Function to check if a given string is a palindrome
int isPalindrome(char s[]){
  // Iterate through the first half of the string
  for(int i=0; i<strlen(s)/2; i++){
    // Check if the character at current index is same as its mirror index
    if(s[i]==s[strlen(s)-1-i]){
      // If yes, continue to next character
      continue;
    }else{
      // If no, return 0 as the string is not a palindrome
      return 0;
    }
  }
  // If we reach here, it means all characters in the first half are same as their mirror index
  // So, the string is a palindrome
  return 1;
}

int main(){
  // Declare a string variable to store user input
  char s[1000];
  // Take user input and store it in the string variable
  scanf("%s", s);
  // Check if the given string is a palindrome and its first half is also a palindrome
  if(isPalindrome(s) && isPalindrome(s) == isPalindrome(s+strlen(s)/2)){
    // If yes, print "Yes"
    printf("Yes\n");
  }else{
    // If no, print "No"
    printf("No\n");
  }
  // Return 0 to indicate successful execution of the program
  return 0;
}

