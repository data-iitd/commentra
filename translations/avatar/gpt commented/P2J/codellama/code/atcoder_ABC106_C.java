
// Importing necessary libraries for various functionalities
import java.util.*;

// Setting the recursion limit to a high value to allow deep recursion
Thread.setStackSize(10 * 7);

// Defining constants for infinity, epsilon, and a modulus value
final int inf = 10 * 20;
final double eps = 1.0 / 10 * 10;
final int mod = 10 * 9 + 7;

// Defining direction vectors for 4-way and 8-way movement
final int[][] dd = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
final int[][] ddn = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

// Function to read a line of integers from input
static int[] LI() {
    return Arrays.stream(S().split(" ")).mapToInt(Integer::parseInt).toArray();
}

// Function to read a line of integers from input and convert them to zero-based index
static int[] LI_() {
    return Arrays.stream(S().split(" ")).map(x -> Integer.parseInt(x) - 1).toArray();
}

// Function to read a line of floats from input
static double[] LF() {
    return Arrays.stream(S().split(" ")).mapToDouble(Double::parseDouble).toArray();
}

// Function to read a line of strings from input
static String[] LS() {
    return S().split(" ");
}

// Function to read a single integer from input
static int I() {
    return Integer.parseInt(S());
}

// Function to read a single float from input
static double F() {
    return Double.parseDouble(S());
}

// Function to read a single string from input
static String S() {
    return new Scanner(System.in).nextLine();
}

// Function to print a string and flush the output buffer
static void pf(String s) {
    System.out.print(s);
    System.out.flush();
}

// Main function to process the input and return the result
static int main() {
    // Reading a string from input
    String s = S();
    // Reading an integer k from input
    int k = I();
    int l = 0; // Initialize a counter for leading '1's

    // Count the number of leading '1's in the string
    for (char c : s.toCharArray()) {
        if (c != '1') {
            break;
        }
        l++;
    }

    // If the count of leading '1's is greater than or equal to k, return 1
    if (l >= k) {
        return 1;
    }

    // Otherwise, return the character at position l in the string
    return s.charAt(l);
}

// Print the result of the main function
pf(String.valueOf(main()));

