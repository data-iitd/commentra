
import java.io.*;  // Importing necessary modules
import java.util.*;  // Importing everything from the util module

// Define input functions
static int[] I() throws Exception {  // Read a list of integers
    return Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
}

static String IS() throws Exception {  // Read a single string
    return br.readLine();
}

static int IN() throws Exception {  // Read an integer
    return Integer.parseInt(br.readLine());
}

static double IF() throws Exception {  // Read a float
    return Double.parseDouble(br.readLine());
}

// Define output functions
static void O(int x) {  // Print an integer
    System.out.print(x + " ");
}

static void O(double x) {  // Print a float
    System.out.print(x + " ");
}

static void O(String x) {  // Print a string
    System.out.print(x + " ");
}

static void OL() {  // Print a new line
    System.out.println();
}

// Define main function
public static void main(String[] args) throws Exception {
    // Read the number of elements
    int n = IN();

    // Read the list of elements
    int[] l = I();

    // Initialize variables
    int f = 1;  // Flag variable
    Arrays.sort(l);  // Sort the list
    int c = 0;  // Counter variable

    // Iterate through the list to find the maximum number of unique elements
    for (int i : l) {
        if (i > c) {
            c++;  // Increment the counter if the current element is greater than the counter
        }
    }

    // Print the result
    O(c + 1);  // Print the maximum number of unique elements
    OL();  // Print a new line
}

