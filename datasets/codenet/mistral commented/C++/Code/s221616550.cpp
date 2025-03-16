#include <iostream>
using namespace std;

// Function to check if a given string is a palindrome
bool isPalindrome(string s){
  // Iterate through the first half of the string
  for(int i=0; i<s.length()/2; i++){
    // Check if the character at current index is same as its mirror index
    if(s[i]==s[s.length()-1-i]){
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
  // Declare a string variable to store user input
  string s;
  // Take user input and store it in the string variable
  cin >> s;
  // Check if the given string is a palindrome and its first half is also a palindrome
  if(isPalindrome(s) && isPalindrome(s.substr(0,s.length()/2))){
    // If yes, print "Yes"
    cout << "Yes" << endl;
  }else{
    // If no, print "No"
    cout << "No" << endl;
  }
  // Return 0 to indicate successful execution of the program
  return 0;
}