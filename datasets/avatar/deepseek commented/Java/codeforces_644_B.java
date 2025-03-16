
import java.util.* ; 

/**
 * Main class to manage task processing with a buffer.
 */
public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        int n = sc.nextInt ( ) ; // Read the number of tasks
        int b = sc.nextInt ( ) ; // Read the buffer size
        long [ ] ans = new long [ n ] ; // Array to store task completion times
        LinkedList < Long > q = new LinkedList < > ( ) ; // Queue to manage buffer

        /**
         * Process each task
         */
        for ( int i = 0 ; i < n ; i ++ ) { 
            int t = sc.nextInt ( ) ; // Read the task's start time
            int d = sc.nextInt ( ) ; // Read the task's duration

            /**
             * Remove completed tasks from the front of the queue
             */
            while ( ! q.isEmpty ( ) && q.getFirst ( ) <= t ) { 
                q.pollFirst ( ) ; 
            }

            /**
             * Check if the task can be added to the buffer
             */
            if ( q.size ( ) <= b ) { 
                ans [ i ] = ( q.isEmpty ( ) ? t : q.getLast ( ) ) + d ; 
                q.add ( ans [ i ] ) ; 
            } else { 
                ans [ i ] = - 1 ; 
            }
        }

        /**
         * Output the completion times of all tasks
         */
        for ( int i = 0 ; i < n ; ++ i ) { 
            System.out.print ( ans [ i ] + " " ) ; 
        } 
    } 
}
