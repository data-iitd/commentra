
// Read input from the user and convert it to a string
Scanner scanner = new Scanner(System.in);
String s = scanner.nextLine();

// Initialize an empty string to store the resulting characters
String myStr = "";

// Iterate through each character in the input string
for (int i = 0; i < s.length(); i++) {
    // Check if the character is '0' or '1'
    if (s.charAt(i) == '0' || s.charAt(i) == '1') {
        // If it is, append it to the result string
        myStr += s.charAt(i);
    }
    // Check if the character is 'B' and the result string is not empty
    else if (s.charAt(i) == 'B' && myStr.length()!= 0) {
        // If it is, remove the last character from the result string
        myStr = myStr.substring(0, myStr.length() - 1);
    }
}

// Print the final result string
System.out.println(myStr);
