import java.util.* ; 

public class Main { 
    public static void main ( String arg [ ] ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        int n = sc.nextInt ( ) ; // Read the number of elements
        char ch [ ] = new char [ n ] ; // Declare a character array to store the result
        int s1 = 0 , s2 = 0 ; // Initialize sums for two paths
        int i , j = 0 , flag = 0 , dif = 0 ; // Declare loop variables and a flag for invalid configuration

        // Loop to read inputs and decide paths
        for ( i = 0 ; i < n ; i ++ ) { 
            int x = sc.nextInt ( ) ; // Read the next integer for path 'x'
            int y = sc.nextInt ( ) ; // Read the next integer for path 'y'
            int temp1 = s1 + x ; // Calculate temporary sum for path 'x'
            int temp2 = s2 + y ; // Calculate temporary sum for path 'y'

            // Check if adding to path 'x' or 'y' is valid
            if ( Math.abs ( temp1 - s2 ) <= 500 ) { 
                s1 += x ; // Update sum for path 'x'
                ch [ j ++ ] = 'A' ; // Append 'A' to the result array
                continue ; // Continue to the next iteration
            } 
            if ( Math.abs ( temp2 - s1 ) <= 500 ) { 
                s2 += y ; // Update sum for path 'y'
                ch [ j ++ ] = 'G' ; // Append 'G' to the result array
                continue ; // Continue to the next iteration
            } 
            flag = 1 ; // Set flag to indicate invalid configuration
            break ; // Break out of the loop
        } 

        // Handle the result based on the flag
        if ( flag == 1 ) 
            System.out.println ( - 1 ) ; // Print -1 if configuration is invalid
        else { 
            String ans = "" ; 
            ans = ans.valueOf ( ch ) ; // Convert character array to string
            System.out.println ( ans ) ; // Print the result string
        } 
    } 
}
