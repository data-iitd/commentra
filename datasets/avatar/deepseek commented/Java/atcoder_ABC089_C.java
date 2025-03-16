
import java.io.OutputStream ; import java.io.IOException ; import java.io.InputStream ; import java.io.PrintWriter ; import java.util.Arrays ; import java.util.Scanner ; 
// Import necessary classes for input/output operations and array manipulations.

public class Main { 
    public static void main ( String [ ] args ) { 
        InputStream inputStream = System.in ; 
        OutputStream outputStream = System.out ; 
        Scanner in = new Scanner ( inputStream ) ; 
        PrintWriter out = new PrintWriter ( outputStream ) ; 
        // Set up input and output streams.

        TaskC solver = new TaskC ( ) ; 
        solver.solve ( 1 , in , out ) ; 
        out.close ( ) ; 
        // Create an instance of TaskC and solve the problem.
    } 

    static class TaskC { 
        public void solve ( int testNumber , Scanner in , PrintWriter out ) { 
            int n = in.nextInt ( ) ; 
            long [ ] cnt = new long [ 5 ] ; 
            Arrays.fill ( cnt , 0 ) ; 
            // Read the number of strings and initialize the count array.

            for ( int i = 0 ; i < n ; ++ i ) { 
                String str = in.next ( ) ; 
                if ( str.charAt ( 0 ) == 'M' ) { 
                    cnt [ 0 ] ++ ; 
                } else if ( str.charAt ( 0 ) == 'A' ) { 
                    cnt [ 1 ] ++ ; 
                } else if ( str.charAt ( 0 ) == 'R' ) { 
                    cnt [ 2 ] ++ ; 
                } else if ( str.charAt ( 0 ) == 'C' ) { 
                    cnt [ 3 ] ++ ; 
                } else if ( str.charAt ( 0 ) == 'H' ) { 
                    cnt [ 4 ] ++ ; 
                } 
                // Count the occurrences of each character at the start of the strings.
            } 

            long res = cnt [ 0 ] * cnt [ 1 ] * cnt [ 2 ] + cnt [ 0 ] * cnt [ 1 ] * cnt [ 3 ] + cnt [ 0 ] * cnt [ 1 ] * cnt [ 4 ] + cnt [ 0 ] * cnt [ 2 ] * cnt [ 3 ] + cnt [ 0 ] * cnt [ 2 ] * cnt [ 4 ] + cnt [ 0 ] * cnt [ 3 ] * cnt [ 4 ] + cnt [ 1 ] * cnt [ 2 ] * cnt [ 3 ] + cnt [ 1 ] * cnt [ 2 ] * cnt [ 4 ] + cnt [ 1 ] * cnt [ 3 ] * cnt [ 4 ] + cnt [ 2 ] * cnt [ 3 ] * cnt [ 4 ] ; 
            out.println ( res ) ; 
            // Calculate the number of combinations and print the result.
        } 
    } 
}

