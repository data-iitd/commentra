// Read input from the user and convert it to a string
String s = String.valueOf(sc.next());

// Initialize an empty string to store the resulting characters
String my_str = "";

// Iterate through each character in the input string
for (int i = 0; i < s.length(); i++) {
    // Check if the character is '0' or '1'
    if (s.charAt(i) == '0' || s.charAt(i) == '1') {
        // If it is, append it to the result string
        my_str += s.charAt(i);
    }
    // Check if the character is 'B' and the result string is not empty
    else if (s.charAt(i) == 'B' && my_str.length()!= 0) {
        // If it is, remove the last character from the result string
        my_str = my_str.substring(0, my_str.length() - 1);
    }
}

// Print the final result string
System.out.println(my_str);

