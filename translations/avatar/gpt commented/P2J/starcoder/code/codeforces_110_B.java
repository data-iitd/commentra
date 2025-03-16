// Define a constant string containing the characters 'a', 'b', 'c', and 'd'
public static final String LUCKY = "abcd";

// Read an integer input from the user, which determines the length of the output string
Scanner scanner = new Scanner(System.in);
int n = scanner.nextInt();

// Initialize an empty string to store the result
String s = "";

// Loop through a range of 'n' to build the output string
for (int i = 0; i < n; i++) {
    // Append the character from LUCKY based on the current index modulo 4
    // This ensures that the characters 'a', 'b', 'c', 'd' are repeated in the output
    s += LUCKY.charAt(i % 4);
}

// Print the final constructed string
System.out.println(s);

