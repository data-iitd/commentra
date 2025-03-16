#include <iostream>
using namespace std;

// Function to check if a given string is a palindrome
bool isPalindrome(string s){
  // Loop through the first half of the string
  for(int i=0; i<s.length()/2; i++){
    // Compare characters from the start and end of the string
    if(s[i] == s[s.length()-1-i]) 
      continue; // If they match, continue to the next iteration
    else 
      return false; // If they don't match, return false
  }
  return true; // If all characters matched, return true
}

int main(){
  string s; // Declare a string variable to hold user input
  cin >> s; // Read input from the user

  // Check if the entire string is a palindrome and if the first half is also a palindrome
  if(isPalindrome(s) && isPalindrome(s.substr(0, s.length()/2))){
    cout << "Yes" << endl; // Output "Yes" if both conditions are true
  } else {
    cout << "No" << endl; // Output "No" if either condition is false
  }
  
  return 0; // Return 0 to indicate successful execution
}
