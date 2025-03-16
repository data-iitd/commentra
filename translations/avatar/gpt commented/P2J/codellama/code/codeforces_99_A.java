// Read input from the user
Scanner sc = new Scanner(System.in);
String l = sc.nextLine();

// Split the input string into two parts using '.' as the delimiter
String[] l = l.split("\\.");

// Convert the first part of the input into a list of characters
char[] s = l[0].toCharArray();

// Convert the second part of the input into a list of characters
char[] p = l[1].toCharArray();

// Extract the first character from the second part and convert it to an integer
int i = Integer.parseInt(p[0] + "");

// Check if the last character of the first part is '9'
if (s[s.length - 1] == '9') {
    // If it is '9', print the message "GOTO Vasilisa."
    System.out.println("GOTO Vasilisa.");
}
// Check if the last character is not '9' and the integer i is less than 5
else if (s[s.length - 1] != '9' && i < 5) {
    // If both conditions are true, join the list of characters into a string and print it
    String s = new String(s);
    System.out.println(s);
} else {
    // If the last character is not '9' and i is 5 or more
    // Join the list of characters into a string, convert it to an integer, increment it by 1, and convert it back to a string
    String s = new String(s);
    int s1 = Integer.parseInt(s);
    s1++;
    s = s1 + "";
    // Print the incremented value
    System.out.println(s);
}

