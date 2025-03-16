
import java.io.IOException ;  // Importing IOException for handling input/output exceptions
import java.io.InputStream ;  // Importing InputStream for reading input from standard input
import java.io.PrintWriter ; // Importing PrintWriter for writing output to standard output
import java.util.ArrayList ;
import java.util.Arrays ;
import java.util.Collection ;
import java.util.Collections ;
import java.util.Comparator ;
import java.util.HashMap ;
import java.util.HashSet ;
import java.util.InputMismatchException ;
import java.util.PriorityQueue ;
import java.util.Random ;
import java.util.Scanner ;
import java.util.Stack ;
import java.util.TreeMap ;
import java.util.TreeSet ;

public class Main {

 static int N ; // Declaring a static integer variable named N
 static int MOD = ( int ) ( 1e9 + 7 ) ; // Declaring a static integer constant named MOD

 public static void main ( String args [ ] ) { // Main method
 Scanner in = new Scanner ( System.in ) ; // Creating a new Scanner object for reading input
 PrintWriter out = new PrintWriter ( System.out ) ; // Creating a new PrintWriter object for writing output
 int t = in.nextInt ( ) ; // Reading the number of test cases

 while ( t -- > 0 ) { // Starting a while loop that runs t times
 long n = in.nextInt ( ) ; // Reading the value of n
 long a = in.nextInt ( ) ; // Reading the value of a
 long b = in.nextInt ( ) ; // Reading the value of b

 if ( n < a ) { // Checking if n is less than a
 out.println ( "No" ) ; // If true, printing "No" and continuing to the next test case
 continue ; // Using the continue statement to skip the rest of the current iteration
 }

 if ( a == b ) { // Checking if a is equal to b
 if ( n % a == 0 ) { // Checking if n is divisible by a
 out.println ( "Yes" ) ; // If true, printing "Yes"
 } else { // If false
 out.println ( "No" ) ; // Printing "No"
 }
 continue ; // Using the continue statement to skip the rest of the current iteration
 }

 long x = b / ( b - a ) ; // Calculating the value of x
 if ( n > x * a ) { // Checking if n is greater than x * a
 out.println ( "Yes" ) ; // If true, printing "Yes" and continuing to the next test case
 continue ; // Using the continue statement to skip the rest of the current iteration
 }

 long low = 1 ; // Initializing a long variable named low to 1
 long high = x + 1 ; // Initializing a long variable named high to x + 1
 long ans = 1 ; // Initializing a long variable named ans to 1

 while ( low <= high ) { // Starting a while loop that runs until low is less than or equal to high
 long mid = ( low + high ) / 2 ; // Calculating the middle value of low and high
 if ( mid * a < n ) { // Checking if mid * a is less than n
 low = mid + 1 ; // If true, setting low to mid + 1
 } else { // If false
 ans = mid ; // Setting ans to mid
 high = mid - 1 ; // Setting high to mid - 1
 }
 }

 if ( n > ( ans - 1 ) * b && n < ans * a ) { // Checking if n is between (ans - 1) * b and ans * a
 out.println ( "No" ) ; // If true, printing "No"
 } else { // If false
 out.println ( "Yes" ) ; // Printing "Yes"
 }
 }

 out.close ( ) ; // Closing the PrintWriter object
 }
}

This code now includes comments for each logical block. Let me know if you need any further assistance.