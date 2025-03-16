import java.util.* ; // Importing the required utility classes

public class Main {
    // Final static constant for the maximum size of the array
    final static int NUM = ( int ) ( 1e5 + 2 ) ;

    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in ) ; // Creating a Scanner object to read input
        int N = sc.nextInt ( ) ; // Reading the number of elements in the array

        // Creating an empty HashMap to store the index of each unique element
        HashMap < Integer , Integer > map = new HashMap < > ( ) ;

        // Creating an empty PriorityQueue to store the elements in ascending order
        PriorityQueue < Integer > nums = new PriorityQueue < > ( ) ;

        // Reading the elements one by one and adding them to the PriorityQueue and HashMap
        for ( int i = 0 ; i < N ; i ++ ) {
            int tmp = sc.nextInt ( ) ; // Reading an element
            nums.add ( tmp ) ; // Adding the element to the PriorityQueue
            map.put ( tmp , i ) ; // Adding the index of the element to the HashMap
        }

        int bin = 0 ; // Initializing a binary index variable
        int diff = 0 ; // Initializing a variable to store the difference in parity between elements

        // Processing the elements in the PriorityQueue
        while ( ! nums.isEmpty ( ) ) {
            int num = nums.poll ( ) ; // Polling an element from the PriorityQueue
            int idx = map.get ( num ) ; // Getting the index of the element from the HashMap

            // Checking if the binary index and the index of the current element have opposite parity
            if ( ( bin % 2 ) != ( idx % 2 ) ) {
                diff ++ ; // Incrementing the difference if the condition is true
            }

            bin ++ ; // Incrementing the binary index
            bin %= 2 ; // Setting the binary index to 0 or 1 based on the current parity
        }

        // Calculating and printing the answer
        int ans = ( diff / 2 ) ;
        System.out.println ( ans ) ;
    }
}
