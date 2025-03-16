#######
# Code
#######

// Import necessary libraries
import java.util.*;

// Define constants
final int inf = 1000000000;
final int mod = 1000000007;
final int[][] dd = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
final int[][] ddn = { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };

// Function to read an integer list from standard input
List<Integer> LI( )
{
    String[] s = br.readLine().split(" ");
    List<Integer> l = new ArrayList<Integer>();
    for ( int i = 0; i < s.length; i++ )
    {
        l.add( Integer.parseInt( s[i] ) );
    }
    return l;
}

// Function to read an integer from standard input
int I( )
{
    return Integer.parseInt( br.readLine() );
}

// Function to read a float from standard input
float F( )
{
    return Float.parseFloat( br.readLine() );
}

// Function to read a list from standard input, split by space
List<String> LS( )
{
    return br.readLine().split(" ");
}

// Function to read a string from standard input
String S( )
{
    return br.readLine();
}

// Main function
void main( )
{
    // Read input values
    int a = I();
    int b = I();
    int c = I();
    int d = I();

    // Calculate the maximum product of pairs of numbers
    int result = Math.max(a*c, b*d, a*d, b*c);

    // Print the result
    System.out.println(result);
}

// Call the main function
main();

