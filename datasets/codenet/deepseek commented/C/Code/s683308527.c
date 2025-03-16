#include<stdio.h>  // Include necessary headers
#include<string.h> // Include necessary headers

int main(){
  int n;  // Declare an integer to store the number of lines
  char s[10010],*c;  // Declare a character array to store the input line and a pointer for string operations
  scanf("%d%*c",&n);  // Read the number of lines and consume the newline character
  while(n--){  // Loop through each line
    fgets(s,1010,stdin);  // Read the input line
    while(c=strstr(s,"Hoshino"))*(c+6)='a';  // Replace "Hoshino" with "Hoshina"
    printf("%s",s);  // Print the modified line
  }
  return 0;  // Return 0 to indicate successful execution
}
