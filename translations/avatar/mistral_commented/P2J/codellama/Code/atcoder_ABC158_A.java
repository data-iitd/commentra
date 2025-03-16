// Read a line from the standard input
String stdin = scanner.nextLine();

// Assign the value of stdin to the variable s
String s = stdin;

// Initialize the variable result with "Yes" if "A" and "B" are present in s, otherwise initialize it with "No"
String result = "Yes";
if (s.contains("A") && s.contains("B")) {
    result = "Yes";
} else {
    result = "No";
}

// Print the value of the variable result
System.out.println(result);

