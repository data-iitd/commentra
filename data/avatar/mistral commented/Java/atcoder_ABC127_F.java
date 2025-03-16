
import java.io.* ; // For handling input and output
import java.util.* ; // For using various utility classes

public class Main {
    static OutputStream outputStream = System.out ; // Output stream to write the result
    static PrintWriter out = new PrintWriter ( outputStream ) ; // PrintWriter to write the result in a formatted way

    public static void main ( String [ ] args ) throws IOException {
        BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ; // Read input from the standard input
        int t = Integer.parseInt ( br.readLine ( ) ) ; // Read the number of test cases

        String [ ] s ; // Array to store each line of input
        PriorityQueue < Integer > pqmax = new PriorityQueue < Integer > ( ) ; // Max Heap to store the maximum elements
        PriorityQueue < Integer > pqmin = new PriorityQueue < Integer > ( new Comparator < Integer > ( ) { // Min Heap to store the minimum elements with a custom comparator
            public int compare ( Integer x , Integer y ) {
                return y - x ; // Comparator to compare the elements in descending order
            }
        } ) ;
        long sumMin = 0 , sumMax = 0 , sumb = 0 ; // Variables to store the sum of minimum and maximum elements and the sum of the current element
        int min = 0 ; // Variable to store the minimum element

        while ( t -- > 0 ) { // Loop through all the test cases
            s = br.readLine ( ).split ( " " ) ; // Read each line of input and split it into an array of strings

            if ( s [ 0 ].charAt ( 0 ) == '2' ) { // If the first character of the line is '2'
                long ans = min ; // Answer is the product of the minimum element and the size of the min heap
                ans *= pqmin.size ( ) ;
                ans -= sumMin ; // Subtract the sum of minimum elements before the current minimum
                long ans1 = min ; // Answer1 is the product of the minimum element and the size of the max heap
                ans1 = sumMax - ans1 ; // Subtract the sum of maximum elements before the current minimum
                out.println ( min + " " + ( ans + ans1 + sumb ) ) ; // Print the answer
            } else { // Else the first character of the line is not '2'
                int in = Integer.parseInt ( s [ 1 ] ) ; // Read the integer value from the input
                sumb += Long.parseLong ( s [ 2 ] ) ; // Add the long value to the sum of the current element

                if ( in > min ) { // If the input is greater than the current minimum
                    pqmax.add ( in ) ; // Add the input to the max heap
                    sumMax += in ; // Add the input to the sum of maximum elements
                } else { // Else the input is smaller than the current minimum
                    pqmin.add ( in ) ; // Add the input to the min heap
                    sumMin += in ; // Add the input to the sum of minimum elements
                }

                if ( pqmin.size ( ) > pqmax.size ( ) ) { // If the size of min heap is greater than the size of max heap
                    sumMax += pqmin.peek ( ) ; // Add the minimum element to the sum of maximum elements
                    sumMin -= pqmin.peek ( ) ; // Subtract the minimum element from the sum of minimum elements
                    pqmax.add ( pqmin.poll ( ) ) ; // Add the polled element from min heap to max heap
                } else if ( pqmin.size ( ) < pqmax.size ( ) ) { // Else if the size of min heap is smaller than the size of max heap
                    sumMax -= pqmax.peek ( ) ; // Subtract the maximum element from the sum of maximum elements
                    sumMin += pqmax.peek ( ) ; // Add the maximum element to the sum of minimum elements
                    pqmin.add ( pqmax.poll ( ) ) ; // Add the polled element from max heap to min heap
                }

                min = pqmin.peek ( ) ; // Update the minimum element
            }
        }

        out.close ( ) ; // Close the output stream and print writer
    }
}

