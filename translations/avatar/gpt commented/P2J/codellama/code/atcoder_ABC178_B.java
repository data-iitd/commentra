
// Import necessary libraries for mathematical operations, data structures, and system functions
import java.util.*;

// Set the maximum recursion limit to handle deep recursion cases
Thread.setStackSize(10 * 1024 * 1024);

// Define a large constant for infinity
final int inf = 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10;

// Define a modulus value commonly used in competitive programming
final int mod = 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7;

// Define directional movements for 4 directions (up, right, down, left)
final int[][] dd = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// Define diagonal movements for 8 directions (including diagonals)
final int[][] ddn = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

// Function to read a line of input and return it as a list of integers
ArrayList<Integer> LI() {
    String[] s = sc.nextLine().split(" ");
    ArrayList<Integer> l = new ArrayList<Integer>();
    for (String si : s) {
        l.add(Integer.parseInt(si));
    }
    return l;
}

// Function to read a single integer from input
int I() {
    return Integer.parseInt(sc.nextLine());
}

// Function to read a single float from input
float F() {
    return Float.parseFloat(sc.nextLine());
}

// Function to read a line of input and return it as a list of strings
ArrayList<String> LS() {
    return new ArrayList<String>(Arrays.asList(sc.nextLine().split(" ")));
}

// Function to read a single string from input
String S() {
    return sc.nextLine();
}

// Main function to execute the core logic of the program
int main() {
    // Read four integers from input
    int a = I();
    int b = I();
    int c = I();
    int d = I();
    
    // Calculate the maximum value from the products of the pairs and return it
    return Math.max(a * c, b * d, a * d, b * c);
}

// Print the result of the main function
System.out.println(main());

