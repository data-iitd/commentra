#######
# Code
#######

// Importing necessary libraries
import java.util.*;

// Defining constants
final int INF = 1000000000;
final double EPS = 1.0 / 1000000000.0;
final int MOD = 1000000007;

// Defining direction vectors
final int[][] dd = new int[][] { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
final int[][] ddn = new int[][] { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };

// Function to read a list of integers from standard input
static ArrayList<Integer> LI( ) {
    return new ArrayList<>(Arrays.asList(Arrays.stream(System.in.readLine().split(" ")).mapToInt(Integer::parseInt).toArray()));
}

// Function to read a list of integers from standard input, subtracting 1 from each element
static ArrayList<Integer> LI_( ) {
    return new ArrayList<>(Arrays.asList(Arrays.stream(System.in.readLine().split(" ")).map(i -> Integer.parseInt(i) - 1).toArray()));
}

// Function to read a list of floats from standard input
static ArrayList<Double> LF( ) {
    return new ArrayList<>(Arrays.asList(Arrays.stream(System.in.readLine().split(" ")).mapToDouble(Double::parseDouble).toArray()));
}

// Function to read a single line from standard input as a list of strings
static ArrayList<String> LS( ) {
    return new ArrayList<>(Arrays.asList(System.in.readLine().split(" ")));
}

// Function to read a single integer from standard input
static int I( ) {
    return Integer.parseInt(System.in.readLine());
}

// Function to read a single float from standard input
static double F( ) {
    return Double.parseDouble(System.in.readLine());
}

// Function to read a single string from standard input
static String S( ) {
    return System.in.readLine();
}

// Function to print a string with a newline character at the end
static void pf(String s) {
    System.out.println(s);
}

// Main function
public static void main( ) {
    // Reading input string and number of occurrences of '1' required
    String s = S( );
    int k = I( );

    // Finding the length of the substring consisting only of '1's
    int l = 0;
    for (char c : s.toCharArray()) {
        if (c!= '1') {
            // If the length of the substring is greater than or equal to the required number of occurrences, return 1
            if (l >= k) {
                pf("1");
                return;
            }
            break;
        }
        l++;
    }

    // If the length of the substring is less than the required number of occurrences, return the character after the substring
    pf(s.charAt(l));
}

// 