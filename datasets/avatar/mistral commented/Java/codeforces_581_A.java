
import java.util.* ; // Importing the utility class Scanner

public class Main { // Defining the main class

    public static void main ( String [ ] args ) { // Starting the main method
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input

        int a , b ; // Declaring two integer variables a and b

        a = sc.nextInt ( ) ; // Reading the first integer input and assigning it to variable a
        b = sc.nextInt ( ) ; // Reading the second integer input and assigning it to variable b

        int count = 0 ; // Initializing the count variable to 0

        while ( true ) { // Starting an infinite loop
            if ( a > 0 && b > 0 ) { // Checking if both a and b are greater than 0
                count ++ ; // Incrementing the count variable if both conditions are true
                a -- ; // Decrementing the value of variable a by 1
                b -- ; // Decrementing the value of variable b by 1
            } else { // If either a or b is not greater than 0
                break ; // Exiting the loop
            }
        }

        int ans = a / 2 + b / 2 ; // Calculating the answer by dividing each number by 2 and summing the results

        System.out.println ( count + " " + ans ) ; // Printing the count and answer to the console
    }
}

These comments should provide a clear understanding of what each part of the code does.