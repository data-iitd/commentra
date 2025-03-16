import java.util.Scanner ; // Importing the Scanner class for user input

public class Main { // Defining the main class
    public static void main ( String [ ] args ) { // Starting point of the program
        Scanner scanner = new Scanner ( System.in ) ; // Creating a new Scanner object for reading user input
        int N = scanner.nextInt ( ) ; // Reading the number of points from the user

        int [ ] [ ] pos = new int [ N ] [ 2 ] ; // Creating a 2D array of size N x 2 to store the x and y coordinates of the points

        for ( int i = 0 ; i < N ; i ++ ) { // Iterating through each point
            pos [ i ] [ 0 ] = scanner.nextInt ( ) ; // Reading the x coordinate of the point
            pos [ i ] [ 1 ] = scanner.nextInt ( ) ; // Reading the y coordinate of the point
        }

        double sum = 0 ; // Initializing the sum variable to 0

        for ( int i = 0 ; i < N ; i ++ ) { // Iterating through each point
            for ( int j = 0 ; j < N ; j ++ ) { // Iterating through all other points except the current one
                if ( i == j ) continue ; // Skipping the current point when comparing it with itself
                sum += dist ( pos [ i ] [ 0 ] , pos [ i ] [ 1 ] , pos [ j ] [ 0 ] , pos [ j ] [ 1 ] ) ; // Adding the distance between the current and the other point to the sum
            }
        }

        System.out.println ( sum / N ) ; // Printing the average distance between all pairs of points
    }

    private static double dist ( int x1 , int y1 , int x2 , int y2 ) { // Defining the dist function to calculate the Euclidean distance between two points
        return Math.sqrt ( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) ) ; // Returning the calculated distance
    }
}
