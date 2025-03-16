#include <iostream>
using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(string s){
  // Loop through the first half of the string
  for(int i=0;i<s.length()/2;i++){
    // Compare characters from the start and end of the string
    if(s[i]==s[s.length()-1-i]) continue;
    // If any characters do not match, return false
    else return false;
  }
  // If all characters match, return true
  return true;
}

int main(){
  // Declare a string variable to store user input
  string s;
  // Read the input string from the user
  cin >> s;
  // Check if the entire string and its first half are palindromes
  if(isPalindrome(s)&&isPalindrome(s.substr(0,s.length()/2))){
    // Print "Yes" if both conditions are true
    cout << "Yes" << endl;
  }else{
    // Print "No" if either condition is false
    cout << "No" << endl;
  }
  return 0;
}