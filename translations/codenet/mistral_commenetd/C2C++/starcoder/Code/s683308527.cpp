
#include<bits/stdc++.h> // Include standard input/output library
using namespace std; // Include standard namespace

int main(){ // Start of the main function
  int n; // Declare an integer variable 'n' to store the number of strings to be processed
  string s; // Declare a string variable's' to store each string read from the input

  cin>>n; // Read an integer 'n' from the standard input

  while(n--){ // Start of the while loop that processes each string
    getline(cin,s); // Read a string of maximum length 1000 from the standard input into the string's'

    while(int c=s.find("Hoshino")){ // Start of the inner while loop that replaces the substring "Hoshino" with "aana"
      s[c+6]='a'; // Replace the 7th character of the substring "Hoshino" with 'a'
      s[c+7]='a'; // Replace the 8th character of the substring "Hoshino" with 'a'
      s[c+8]='a'; // Replace the 9th character of the substring "Hoshino" with 'a'
      s[c+9]='n'; // Replace the 10th character of the substring "Hoshino" with 'n' to get the substring "aana"
    }

    cout<<s<<endl; // Print the modified string to the standard output
  }

  return 0; // End of the main function with a return value of 0 indicating successful execution
}

