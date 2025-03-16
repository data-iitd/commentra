
import java.util.* ; // Importing the utility class Scanner

public class Main {

 // Main method is the entry point of the Java application
 public static void main ( String [ ] args ) {
 long startTime = System.currentTimeMillis ( ) ; // Start time measurement
 Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input
 int n = sc.nextInt ( ) ; // Reading the number of elements in the array
 long div = ( long ) Math.pow ( 10 , 9 ) + 7 ; // Modulus constant for efficient modular arithmetic
 long [ ] A = new long [ n ] ; // Creating an array of long type with size n
 long ans = 0 ; // Initializing the answer variable to zero

 // Reading the elements of the array A
 for ( int i = 0 ; i < n ; i ++ ) {
 A [ i ] = sc.nextLong ( ) ; // Reading an element of the array A
 }

 // Calculating the answer using the given formula
 for ( int i = 0 ; i < 60 ; i ++ ) { // Looping through all the bits from 0 to 59
 long a = 0 ; // Initializing the variable a to zero
 long count1 = 0 ; // Initializing the variable count1 to zero

 // Counting the number of elements in the array A with the i-th bit set to 1
 for ( int j = 0 ; j < n ; j ++ ) {
 if ( ( A [ j ] >> i & 1 ) == 1 ) // Checking if the i-th bit is set in the j-th element of the array A
 count1 ++ ; // Incrementing the count1 variable
 }

 // Calculating the contribution of the i-th bit to the answer
 a = a + count1 * ( n - count1 ) ; // a = a + (count1 \* (n - count1))

 // Shifting the contribution to the left by (i+1) bits and taking modulo with the modulus constant
 for ( int j = 0 ; j < i ; j ++ ) {
 a = ( a << 1 ) % div ; // a = (a << 1) % div
 }

 // Adding the contribution to the answer
 ans += a ; // ans += a
 ans %= div ; // ans %= div
 }

 // Printing the answer
 System.out.println ( ans ) ; // Printing the answer
 long endTime = System.currentTimeMillis ( ) ; // End time measurement
 System.out.println ( "Time taken by the program is : " + (endTime - startTime) + " milliseconds" ) ; // Printing the time taken by the program to execute
 }
}

I hope these comments will help you understand the code better. Let me know if you have any questions!