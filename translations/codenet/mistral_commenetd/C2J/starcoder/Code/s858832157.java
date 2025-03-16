
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare and initialize variables
        int i = 1; // Initialize counter variable i to 1
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input from stdin
        int Input; // Declare variable to store user input

        while(true)
        {
            // Read user input and store it in the Input variable
            Input = sc.nextInt();

            // Check if user input is 0
            if(Input == 0)
            {
                // If user input is 0, break out of the loop
                break;
            }

            // Print the case number and user input
            System.out.printf("Case %d: %d\n",i,Input);

            // Increment the counter variable i
            i++;
        }
    }
}

