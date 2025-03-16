
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a counter variable 'i' to track the case number and an 'Input' variable to store user input
        int i = 1, Input;

        // Start an infinite loop to continuously accept user input
        while(true) {
            // Read an integer input from the user
            Scanner sc = new Scanner(System.in);
            Input = sc.nextInt();

            // Check if the input is zero, which indicates the end of input
            if(Input == 0) {
                // Exit the loop if the input is zero
                break;
            }

            // Print the case number and the input value
            System.out.println("Case " + i + ": " + Input);

            // Increment the case number for the next iteration
            i++;
        }
    }
}

