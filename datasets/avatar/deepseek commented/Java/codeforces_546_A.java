import java.util.Scanner ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; // Create a Scanner object to read input from the user
        long pandu , vundu , urdu , c = 0 ; // Declare four long integers to store user input and a variable for accumulation

        pandu = sc.nextLong ( ) ; // Read the first long integer input from the user
        vundu = sc.nextLong ( ) ; // Read the second long integer input from the user
        urdu = sc.nextLong ( ) ; // Read the third long integer input from the user

        // The for loop iterates from 1 to urdu (inclusive)
        // In each iteration, it calculates the product of i and pandu and adds it to the variable c
        for ( int i = 1 ; i <= urdu ; i ++ ) { 
            c += i * pandu ; 
        }

        // The if-else statement checks if the value of c is less than vundu
        // If it is, the program prints "0". Otherwise, it prints the difference between c and vundu
        if ( c < vundu ) { 
            System.out.print ( "0" ) ; 
        } else { 
            System.out.print ( c - vundu ) ; 
        } 
    } 
}