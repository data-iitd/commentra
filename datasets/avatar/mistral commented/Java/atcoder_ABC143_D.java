
import java.util.* ; // Import the Java utility classes

public class Main { // Define the main class

    public static void main ( String args [ ] ) { // Define the main method as the entry point of the program
        Scanner scanner = new Scanner ( System.in ) ; // Create a Scanner object to read input from the standard input stream
        int N = scanner.nextInt ( ) ; // Read the first integer N from the standard input and store it in a variable

        List < Integer > L = new ArrayList < > ( N ) ; // Create an empty ArrayList of Integers with a capacity equal to N

        for ( int i = 0 ; i < N ; i ++ ) { // Use a for loop to read N integers from the standard input and add them to the ArrayList
            L.add ( scanner.nextInt ( ) ) ;
        }

        Collections.sort ( L ) ; // Sort the ArrayList using the Collections.sort() method

        int count = 0 ; // Initialize a counter variable to 0

        for ( int i = 0 ; i < N ; i ++ ) { // Use a nested for loop to iterate through all pairs of adjacent elements in the sorted ArrayList
            for ( int j = i + 1 ; j < N ; j ++ ) {
                int a = L.get ( i ) ; // Get the first integer of the pair
                int b = L.get ( j ) ; // Get the second integer of the pair
                int res = find ( L , j + 1 , a + b ) ; // Call the find() method to find the number of elements greater than the sum of the pair
                count = count + res ; // Add the result of the find() method to the counter variable
            }
        }

        System.out.println ( count ) ; // Print the final value of the counter variable to the standard output stream
    }

    public static int find ( List < Integer > li , int from , int target ) { // Define the find() method that takes three arguments: a List of Integers, an index from where to start the search, and a target integer
        int low = from ; // Initialize the lower bound of the binary search
        int upp = li.size ( ) - 1 ; // Initialize the upper bound of the binary search
        int mid = 0 ; // Initialize a variable to store the middle index of the binary search

        if ( upp - low < 0 ) { // Check if the ArrayList is empty or the target integer is less than the first element
            return 0 ;
        } else if ( li.get ( from ) >= target ) { // Check if the target integer is greater than or equal to the first element
            return 0 ;
        } else if ( li.get ( upp ) < target ) { // Check if the target integer is less than the last element
            return upp - low + 1 ;
        }

        while ( upp - low > 1 ) { // Perform the binary search
            mid = ( upp - low + 1 ) % 2 == 0 ? ( low + upp ) / 2 + 1 : ( low + upp ) / 2 ; // Calculate the middle index of the binary search

            if ( li.get ( mid ) >= target ) { // If the middle element is greater than or equal to the target, update the upper bound of the search
                upp = mid ;
            } else { // If the middle element is less than the target, update the lower bound of the search
                low = mid ;
            }
        }

        return low - from + 1 ; // Return the index of the middle element minus the starting index plus one
    }
}