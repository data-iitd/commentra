// Ask the user for a string input
String s = scanner.next();

// Initialize an empty string variable to store the binary string
String my_str = "";

// Iterate through each character in the user input string
for (char c : s.toCharArray()) {
    // If the character is '0' or '1', append it to the binary string
    if (c == '0' || c == '1') {
        my_str += c;
    }
    // If the character is 'B', remove the last character from the binary string before 'B' was encountered
    else if (c == 'B' && my_str.length()!= 0) {
        my_str = my_str.substring(0, my_str.length() - 1);
    }
}

// Print the final binary string
System.out.println(my_str);

