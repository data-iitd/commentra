
import java.util.Scanner; // Importing the Scanner class from the Java standard library

public class Main
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in); // Creating a Scanner object named `input` to read from the standard input

        int n; // Declaring an integer variable `n` to store the user input

        System.out.print("Enter a number: "); // Printing a message to ask the user to enter a number
        n = input.nextInt(); // Reading an integer value from the standard input and storing it in the variable `n`

        if(n%1000==0) // Checking if the remainder of `n` when divided by 1000 is equal to 0
        {
            System.out.println(0); // If the condition is true, we print the value 0 to the standard output
        }
        else
        {
            System.out.println((n/1000+1)*1000-n); // If the condition is false, we calculate the number that is one thousand greater than the quotient of `n` when divided by 1000 and print that value to the standard output
        }
    }
}

