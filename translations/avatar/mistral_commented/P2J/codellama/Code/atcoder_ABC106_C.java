#######
# Code
#######

// Importing necessary libraries
import java.util.*;

// Defining constants
final int inf = 10**20;
final double eps = 1.0 / 10**10;
final int mod = 10**9 + 7;

// Defining direction vectors
final int[][] dd = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
final int[][] ddn = { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };

// Function to read a list of integers from standard input
List<Integer> LI( ) {
    return Arrays.stream(S( ).split(" ")).map(x -> Integer.parseInt(x)).collect(Collectors.toList());
}

// Function to read a list of integers from standard input, subtracting 1 from each element
List<Integer> LI_( ) {
    return Arrays.stream(S( ).split(" ")).map(x -> Integer.parseInt(x) - 1).collect(Collectors.toList());
}

// Function to read a list of floats from standard input
List<Double> LF( ) {
    return Arrays.stream(S( ).split(" ")).map(x -> Double.parseDouble(x)).collect(Collectors.toList());
}

// Function to read a single line from standard input as a list of strings
List<String> LS( ) {
    return Arrays.asList(S( ).split(" "));
}

// Function to read a single integer from standard input
int I( ) {
    return Integer.parseInt(S( ));
}

// Function to read a single float from standard input
double F( ) {
    return Double.parseDouble(S( ));
}

// Function to read a single string from standard input
String S( ) {
    return new Scanner(System.in).nextLine();
}

// Function to print a string with a newline character at the end
void pf(String s) {
    System.out.print(s + "\n");
}

// Main function
void main( ) {
    // Reading input string and number of occurrences of '1' required
    String s = S( );
    int k = I( );

    // Finding the length of the substring consisting only of '1's
    int l = 0;
    for (char c : s.toCharArray( )) {
        if (c != '1') {
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
    pf(s.charAt(l) + "");
}

// Calling the main function and printing the result
main( );

