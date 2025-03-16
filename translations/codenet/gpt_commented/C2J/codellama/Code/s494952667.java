
// Declare a string variable to hold the input string
String str;

// Read a string from standard input
str = scanner.nextLine();

// Calculate the length of the input string
int len = str.length();

// Loop through the string in reverse order
for(int i = len - 1; i >= 0; i--){
  // Output each character of the string in reverse
  System.out.print(str.charAt(i));
}

// Print a newline character after the reversed string
System.out.println();

// Return 0 to indicate successful completion of the program
return 0;

