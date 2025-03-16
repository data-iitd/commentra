// Read input from the standard input (user input)
Scanner scanner = new Scanner(System.in);

// Store the input string in a variable 's'
String s = scanner.nextLine();

// Check if both 'A' and 'B' are present in the input string
// If both are found, set result to "Yes", otherwise set it to "No"
String result = "Yes";
if (s.contains("A") && s.contains("B")) {
    result = "Yes";
} else {
    result = "No";
}

// Print the result indicating whether both 'A' and 'B' were found
System.out.println(result);

