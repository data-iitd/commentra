#include<iostream>  // Include necessary headers
#include<cstring> // Include necessary headers

using namespace std;

int main(){
  int n;  // Declare an integer to store the number of lines
  char s[10010],*c;  // Declare a character array to store the input line and a pointer for string operations
  cin>>n;  // Read the number of lines
  while(n--){  // Loop through each line
    cin.getline(s,1010);  // Read the input line
    while(c=strstr(s,"Hoshino"))*(c+6)='a';  // Replace "Hoshino" with "Hoshina"
    cout<<s;  // Print the modified line
  }
  return 0;  // Return 0 to indicate successful execution
}
