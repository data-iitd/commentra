
import java.util.Scanner; // Import the Scanner class for reading input from the console

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a new Scanner object to read input from the console
        
        int x; // Declare an integer variable x to store the user input

        x = Integer.parseInt(sc.next()); // Read the next token as a String from the console, parse it into an integer value, and assign it to the variable x

        if (x < 1200) { // Check if the value of x is less than 1200
            System.out.println("ABC"); // If the condition is true, print the string "ABC" to the console
        } else {
            System.out.println("ARC"); // If the condition is false, print the string "ARC" to the console
        }

        sc.close(); // Close the Scanner object to free up system resources
    }
}