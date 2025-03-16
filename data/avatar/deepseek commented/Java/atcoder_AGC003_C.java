
import java.util.* ; 

public class Main { 
    // Define a constant for array or list size
    final static int NUM = ( int ) ( 1e5 + 2 ) ; 

    public static void main ( String [ ] args ) { 
        // Initialize a Scanner object to read input
        Scanner sc = new Scanner ( System.in ) ; 
        
        // Read the number of elements
        int N = sc.nextInt ( ) ; 
        
        // Initialize a HashMap to store value and its index
        HashMap < Integer , Integer > map = new HashMap < > ( ) ; 
        
        // Initialize a PriorityQueue to store numbers
        PriorityQueue < Integer > nums = new PriorityQueue < > ( ) ; 
        
        // Read each number, add it to the PriorityQueue, and store its value and index in the HashMap
        for ( int i = 0 ; i < N ; i ++ ) { 
            int tmp = sc.nextInt ( ) ; 
            nums.add ( tmp ) ; 
            map.put ( tmp , i ) ; 
        } 
        
        // Initialize variables to keep track of the current index and the count of differences
        int bin = 0 ; 
        int diff = 0 ; 
        
        // Loop until the PriorityQueue is empty
        while ( ! nums.isEmpty ( ) ) { 
            // Retrieve the next number and its index from the PriorityQueue and HashMap
            int num = nums.poll ( ) ; 
            int idx = map.get ( num ) ; 
            
            // If the current index is not even when bin is even (or vice versa), increment the diff counter
            if ( ( bin % 2 ) != ( idx % 2 ) ) { 
                diff ++ ; 
            } 
            
            // Update bin and take modulo 2 to keep it within 0 or 1
            bin ++ ; 
            bin %= 2 ; 
        } 
        
        // Calculate the answer by dividing diff by 2
        int ans = ( diff / 2 ) ; 
        
        // Print the result
        System.out.println ( ans ) ; 
    } 
}
