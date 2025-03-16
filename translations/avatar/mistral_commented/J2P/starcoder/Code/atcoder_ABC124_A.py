
# Import Scanner class for reading input
import java.util.Scanner ;

# Entry point of the Java application
if __name__ == '__main__':
    sc = java.util.Scanner ( System.in ) ;  # Create a new Scanner object to read input from standard input

    a = int ( sc.next ( ) ) ;  # Read the first integer from standard input and convert it to an integer
    b = int ( sc.next ( ) ) ;  # Read the second integer from standard input and convert it to an integer

    sum = 0 ;  # Initialize sum variable to 0

    for i in range ( 2 ) :  # Iterate through two iterations
        if a >= b :  # Check if a is greater than or equal to b
            sum += a ;  # Add a to sum and decrement a by 1
            a -= 1 ;  # Decrement a by 1
        else :
            sum += b ;  # Add b to sum and decrement b by 1
            b -= 1 ;  # Decrement b by 1

    print ( sum ) ;  # Print the value of sum to standard output

