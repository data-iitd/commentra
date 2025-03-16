
// Importing the Scanner class for reading input from standard input
import java.util.Scanner;

// Function to read a single line from standard input and return it as a string
// with the trailing newline character removed
public static String rs ( ) {
    Scanner sc = new Scanner ( System.in );
    return sc.nextLine ( ).trim ( );
}

// Function to read a single integer from standard input
public static int ri ( ) {
    return Integer.parseInt ( rs ( ) );
}

// Function to read a list of integers from standard input
// Each line of input is assumed to contain space-separated integers
public static int[] ri_ ( ) {
    String[] s = rs ( ).split ( " " );
    int[] a = new int[s.length];
    for ( int i = 0 ; i < s.length ; i++ ) {
        a[i] = Integer.parseInt ( s[i] );
    }
    return a;
}

// Read the number of test cases from standard input
int N = ri ( );

// Initialize the answer to 0
int ans = 0;

// Iterate through all numbers from 1 to N
for ( int i = 1 ; i <= N ; i++ ) {
    // Calculate the contribution of i to the answer
    // The formula is given by the problem statement
    ans += i * ( N / i ) * ( N / i + 1 ) / 2;
}

// Print the answer
System.out.println ( ans );

