
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; // Initialize Scanner object to read input
        int n = sc.nextInt ( ) ; // Read the first integer input, which represents the number of elements
        int m = sc.nextInt ( ) ; // Read the second integer input, which is the threshold value
        
        Queue < Integer > q1 = new LinkedList < > ( ) ; // Initialize queue to store the elements
        Queue < Integer > q2 = new LinkedList < > ( ) ; // Initialize queue to store the indices
        
        for ( int i = 1 ; i <= n ; i ++ ) { 
            q1.add ( sc.nextInt ( ) ) ; // Read each element and add it to q1
            q2.add ( i ) ; // Add the corresponding index to q2
        }
        
        int ans = 0 ; // Initialize ans to store the result
        
        while ( ! q1.isEmpty ( ) ) { // Continue the loop until q1 is empty
            if ( q1.peek ( ) <= m ) { // Check if the front element of q1 is less than or equal to m
                q1.poll ( ) ; // Remove the front element from q1
                ans = q2.poll ( ) ; // Assign the corresponding index to ans and remove it from q2
            } else if ( q1.peek ( ) > m ) { // Check if the front element of q1 is greater than m
                int x = q1.poll ( ) ; // Remove the front element from q1
                int val = x - m ; // Subtract m from the element
                q1.add ( val ) ; // Add the result back to q1
                int val2 = q2.poll ( ) ; // Remove the corresponding index from q2
                q2.add ( val2 ) ; // Add the index back to the end of q2
            }
        }
        
        System.out.println ( ans ) ; // Print the index of the last remaining element
    } 
}
