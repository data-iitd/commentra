import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; // Initialize Scanner to read input
        int n , i , j , p = 97 ; 
        n = sc.nextInt ( ) ; // Read the size of the array from the user
        char c [ ] = new char [ n ] ; // Initialize the character array of size n
        
        // Nested loops to assign characters to the array
        for ( i = 0 ; i < 4 ; i ++ ) { 
            for ( j = i ; j < n ; j += 4 ) { 
                c [ j ] = ( char ) p ; // Assign character and increment ASCII value
            }
            p ++ ; // Increment the ASCII value for the next character
        }
        
        // Print the character array to the console
        for ( i = 0 ; i < n ; i ++ ) { 
            System.out.print ( c [ i ] ) ; 
        }
    } 
}
