
// Define a constant string "abcd"
public static final String LUCKY = "abcd";

// Ask the user to input an integer n
Scanner in = new Scanner(System.in);
System.out.print("Enter an integer n: ");
int n = in.nextInt();

// Initialize an empty string s
String s = "";

// Use a for loop to iterate through the range of integers from 0 to n-1
for (int i = 0; i < n; i++) {
    // Add the character at index i % 4 of the string LUCKY to the string s
    s += LUCKY.charAt(i % 4);
}

// Print the final string s
System.out.println(s);

