// Ask the user for a string input
Scanner sc = new Scanner(System.in);
String s = sc.nextLine();

// Initialize an empty string variable to store the binary string
String myStr = "";

// Iterate through each character in the user input string
for (int i = 0; i < s.length(); i++) {
    // If the character is '0' or '1', append it to the binary string
    if (s.charAt(i) == '0' || s.charAt(i) == '1') {
        myStr += s.charAt(i);
    }
    // If the character is 'B', remove the last character from the binary string before 'B' was encountered
    else if (s.charAt(i) == 'B' && myStr.length() != 0) {
        myStr = myStr.substring(0, myStr.length() - 1);
    }
}

// Print the final binary string
System.out.println(myStr);

