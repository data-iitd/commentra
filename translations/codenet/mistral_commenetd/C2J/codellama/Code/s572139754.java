
import java.util.Scanner; // Importing the Scanner class from the java.util package

public class Main { // Starting the Main class

    public static void main(String[] args) { // Starting the main function

        Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the standard input

        System.out.print("Enter a number: "); // Printing a message to ask the user to enter a number
        int n = sc.nextInt(); // Reading an integer value from the standard input and storing it in the variable `n`

        if(n%1000==0) { // Checking if the remainder of `n` when divided by 1000 is equal to 0
            System.out.println(0); // If the condition is true, we print the value 0 to the standard output
        }
        else {
            System.out.println((n/1000+1)*1000-n); // If the condition is false, we calculate the number that is one thousand greater than the quotient of `n` when divided by 1000 and print that value to the standard output
        }

    } // Ending the main function

} // Ending the Main class

