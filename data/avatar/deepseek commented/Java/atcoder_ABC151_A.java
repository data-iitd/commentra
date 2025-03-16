
import java.io.BufferedReader ; 
import java.io.IOException ; 
import java.io.InputStreamReader ; 

public class Main { 
    public static void main ( String [ ] args ) throws IOException { 
        // Create a BufferedReader to read input from the console
        BufferedReader r = new BufferedReader ( new InputStreamReader ( System.in ) , 1 ) ; 
        
        // Read a single line of input from the user
        String s ; 
        String sl [ ] ; 
        s = r.readLine ( ) ; 
        
        // Increment the first character of the input by 1 and print it
        System.out.printf ( "%c" , s.charAt ( 0 ) + 1 ) ; 
    } 
} 

class RemRing { 
    long module ; 
    
    // Constructor to initialize the module value
    public RemRing ( long module ) { 
        this.module = module ; 
    } 
    
    // Method to calculate the sum modulo module
    public long sum ( long a , long b ) { 
        return ( a + b + module ) % module ; 
    } 
    
    // Method to calculate the difference modulo module
    public long sub ( long a , long b ) { 
        return ( a - b + module ) % module ; 
    } 
    
    // Method to calculate the product modulo module
    public long prod ( long a , long b ) { 
        return ( a * b ) % module ; 
    } 
    
    // Method to calculate the division modulo module
    public long div ( long a , long b ) { 
        return ( a * inv ( b ) ) % module ; 
    } 
    
    // Method to calculate the modular inverse
    public long inv ( long a ) { 
        long b = this.module ; 
        long u = 1 ; 
        long v = 0 ; 
        
        // Extended Euclidean Algorithm to find the modular inverse
        while ( b > 0 ) { 
            long t = a / b ; 
            a -= t * b ; 
            u -= t * v ; 
            long z = a ; 
            a = b ; 
            b = z ; 
            z = u ; 
            u = v ; 
            v = z ; 
        } 
        
        u %= this.module ; 
        if ( u < 0 ) u += this.module ; 
        return u ; 
    } 
}
