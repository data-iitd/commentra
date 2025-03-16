import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        
        // Step 1: Reading Input
        int n = sc.nextInt ( ) ; // Read the size of the array
        int [ ] a = new int [ n ] ; // Initialize the array
        for ( int i = 0 ; i < n ; i ++ ) { 
            a [ i ] = sc.nextInt ( ) ; // Read the elements of the array
        }
        
        // Step 2: Reading a String
        String s = sc.next ( ) ; // Read the string
        
        // Step 3: Initial Sum Calculation
        long sum = 0 ; // Initialize sum to store the sum of elements in array a where corresponding character in s is 'B'
        
        // Step 4: First Loop
        for ( int i = 0 ; i < s.length ( ) ; i ++ ) { 
            char ch = s.charAt ( i ) ; // Get the character at position i in the string s
            if ( ch == 'B' ) sum += a [ i ] ; // Add the element at position i in array a to sum if the character is 'B'
        }
        
        // Step 5: Main Logic
        long ans = sum ; // Initialize ans with the initial sum
        long sum1 = sum ; // Initialize sum1 for further calculations
        
        // First nested loop to calculate the maximum possible sum by flipping characters in s
        for ( int i = 0 ; i < s.length ( ) ; i ++ ) { 
            if ( s.charAt ( i ) == 'A' ) sum1 += a [ i ] ; // Add the element at position i in array a to sum1 if the character is 'A'
            else sum1 -= a [ i ] ; // Subtract the element at position i in array a from sum1 if the character is 'B'
            ans = Math.max ( ans , sum1 ) ; // Update ans with the maximum value between ans and sum1
        }
        
        // Second nested loop to calculate the maximum possible sum by flipping characters in s from right to left
        sum1 = sum ; // Reset sum1 to the initial sum
        for ( int i = s.length ( ) - 1 ; i >= 0 ; i -- ) { 
            if ( s.charAt ( i ) == 'A' ) sum1 += a [ i ] ; // Add the element at position i in array a to sum1 if the character is 'A'
            else sum1 -= a [ i ] ; // Subtract the element at position i in array a from sum1 if the character is 'B'
            ans = Math.max ( ans , sum1 ) ; // Update ans with the maximum value between ans and sum1
        }
        
        // Step 6: Output
        System.out.println ( ans ) ; // Print the maximum sum found
    } 
}
