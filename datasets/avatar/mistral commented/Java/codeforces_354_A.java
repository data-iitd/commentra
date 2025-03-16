import java.util.Scanner ; // Importing the Scanner class for reading input

public class Main { // Defining the main class
    public static void main ( String [ ] args ) { // Defining the main method
        Scanner in = new Scanner ( System.in ) ; // Creating a new Scanner object for reading input from the console

        int N = in.nextInt ( ) ; // Reading the first integer input, which represents the number of elements in the array W
        int L = in.nextInt ( ) ; // Reading the first integer parameter, which represents the length of the first segment
        int R = in.nextInt ( ) ; // Reading the second integer parameter, which represents the length of the second segment
        int QL = in.nextInt ( ) ; // Reading the first integer query, which represents the length of the first query segment
        int QR = in.nextInt ( ) ; // Reading the second integer query, which represents the length of the second query segment

        int [ ] W = new int [ N ] ; // Creating an integer array W of size N
        int [ ] sum = new int [ N + 1 ] ; // Creating an integer array sum of size N+1

        for ( int n = 0 ; n < N ; n ++ ) { // Iterating through each element in the array W
            W [ n ] = in.nextInt ( ) ; // Reading the integer value of each element in the array W
            sum [ n + 1 ] = sum [ n ] + W [ n ] ; // Calculating the sum of all elements from 0 to n+1
        }

        long min = Long.MAX_VALUE ; // Initializing the minimum value to be the maximum long value

        for ( int firstR = 0 ; firstR <= N ; firstR ++ ) { // Iterating through all possible starting indices for the right segment
            int lCount = firstR ; // The length of the left segment is equal to the index of the starting point of the right segment
            int rCount = N - lCount ; // The length of the right segment is equal to the total length of the array minus the length of the left segment

            long cand = sum [ lCount ] * L + ( sum [ N ] - sum [ lCount ] ) * R ; // Calculating the candidate value for the current combination of left and right segments

            int llCount = Math.max ( 0 , lCount - rCount - 1 ) ; // Calculating the length of the overlapping part between the left and right segments, if any
            int rrCount = Math.max ( 0 , rCount - lCount - 1 ) ; // Calculating the length of the overlapping part between the right and left segments, if any

            cand += llCount * QL ; // Adding the contribution of the left overlapping part to the candidate value
            cand += rrCount * QR ; // Adding the contribution of the right overlapping part to the candidate value

            min = Math.min ( cand , min ) ; // Updating the minimum value if the current candidate value is smaller
        }

        System.out.println ( min ) ; // Printing the minimum value as the output
    }
}
