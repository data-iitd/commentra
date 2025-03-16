// Get the input string from the user
String l = sc.nextLine();

// Split the input string using '.' as delimiter and store the list in 'l'
String[] l = l.split("\\.");

// Extract the first and second parts of the list and store them in 's' and 'p' respectively
String[] s = l[0].split("");
String[] p = l[1].split("");

// Get the last character of the string 's' and store it in a variable 'last_char'
String last_char = s[s.length - 1];

// Check if the last character of the string 's' is '9'
if (last_char.equals("9")) {
    // If yes, print the message "GOTO Vasilisa."
    System.out.println("GOTO Vasilisa.");
}

// Else, if the last character is not '9' and the integer value of the first part of 'p' is less than 5
else if (!last_char.equals("9") && Integer.parseInt(p[0]) < 5) {
    // Concatenate all the characters of 's' to form a string
    String s = String.join("", s);
    // Print the string 's'
    System.out.println(s);
}

// Else, if the last character is not '9' and the integer value of the first part of 'p' is greater than or equal to 5
else {
    // Concatenate all the characters of 's' to form a string
    String s = String.join("", s);
    // Increment the last character of the string 's' by 1
    s = String.valueOf(Integer.parseInt(s) + 1);
    // Print the updated string 's'
    System.out.println(s);
}

