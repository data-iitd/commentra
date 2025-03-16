import java.io.PrintWriter ; 
import java.util.ArrayList ; 
import java.util.Arrays ; 
import java.util.Scanner ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        new Main ( ).run ( ) ; 
    } 

    // MOD constant with value 10^9 + 7
    final long MOD = ( long ) 1e9 + 7 ; 

    // Main logic of the program
    void run ( ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        char [ ] cs = sc.next ( ).toCharArray ( ) ; 

        // 2D array dp to store the number of ways to achieve each remainder when the number is divided by 13
        long [ ] [ ] dp = new long [ cs.length ] [ 13 ] ; 

        // Initialize the base variable to represent the current power of 10
        int base = 1 ; 

        // Loop through the character array from the least significant digit to the most significant digit
        for ( int i = 0 ; i < cs.length ; ++ i ) { 
            if ( cs [ cs.length - 1 - i ] == '?' ) { 
                // If the current character is '?', we iterate through all possible digits (0-9)
                for ( int pre = 0 ; pre < 13 ; ++ pre ) { 
                    for ( int next = 0 ; next < 10 ; ++ next ) { 
                        dp [ i ] [ ( base * next + pre ) % 13 ] += ( i > 0 ? dp [ i - 1 ] [ pre ] : ( pre == 0 ? 1 : 0 ) ) ; 
                        dp [ i ] [ ( base * next + pre ) % 13 ] %= MOD ; 
                    } 
                } 
            } else { 
                // If the current character is not '?', we update the dp array based on the actual digit
                int next = cs [ cs.length - 1 - i ] - '0' ; 
                for ( int pre = 0 ; pre < 13 ; ++ pre ) { 
                    dp [ i ] [ ( base * next + pre ) % 13 ] += ( i > 0 ? dp [ i - 1 ] [ pre ] : ( pre == 0 ? 1 : 0 ) ) ; 
                    dp [ i ] [ ( base * next + pre ) % 13 ] %= MOD ; 
                } 
            } 
            // Update the base variable to the next power of 10 modulo 13
            base = base * 10 % 13 ; 
        } 

        // Print the number of ways to achieve the remainder 5 when the number is divided by 13
        System.out.println ( dp [ dp.length - 1 ] [ 5 ] ) ; 
    } 

    // Method to print debug information (optional)
    void tr ( Object...objects ) { 
        System.out.println ( Arrays.deepToString ( objects ) ) ; 
    } 
}
