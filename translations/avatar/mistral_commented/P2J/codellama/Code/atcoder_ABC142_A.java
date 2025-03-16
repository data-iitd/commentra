// Import the java.util.Scanner class for input
import java.util.Scanner;

// Define a function to read an integer input from the user
public static int nextInt() {
    // Create a new Scanner object to read input from the user
    Scanner scanner = new Scanner(System.in);
    // Read an integer input from the user and return it
    return scanner.nextInt();
}

// Define a function to read a list of integers from the user
public static int[] nextInts() {
    // Create a new Scanner object to read input from the user
    Scanner scanner = new Scanner(System.in);
    // Read a list of integers from the user and return it
    return scanner.nextInt();
}

// Read an integer `n` from the user
int n = nextInt();
// Initialize a variable `t` to zero
int t = 0;
// Iterate through the range of integers from 0 to n-1
for (int i = 0; i < n; i++) {
    // Check if the index i is odd
    if (i + 1 % 2 == 1) {
        // If it is odd, increment the variable t by 1
        t += 1;
    }
}
// Print the result t/n as the output
System.out.println(t / n);

