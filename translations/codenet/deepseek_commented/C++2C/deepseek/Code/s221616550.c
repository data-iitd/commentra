#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a string is a palindrome
bool isPalindrome(char* s){
  // Loop through the first half of the string
  for(int i=0;i<strlen(s)/2;i++){
    // Compare characters from the start and end of the string
    if(s[i]==s[strlen(s)-1-i]) continue;
    // If any characters do not match, return false
    else return false;
  }
  // If all characters match, return true
  return true;
}

int main(){
  // Declare a character array to store user input
  char s[100];
  // Read the input string from the user
  scanf("%s", s);
  // Check if the entire string and its first half are palindromes
  if(isPalindrome(s)&&isPalindrome(strncpy(s, s, strlen(s)/2))){
    // Print "Yes" if both conditions are true
    printf("Yes\n");
  }else{
    // Print "No" if either condition is false
    printf("No\n");
  }
  return 0;
}
