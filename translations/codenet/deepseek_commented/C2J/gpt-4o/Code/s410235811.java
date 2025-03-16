import java.util.Scanner;  // Import the Scanner class for user input

public class Main {        // Define the Main class
    public static void main(String[] args) {  // Define the main method, the entry point of the program
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int n = scanner.nextInt();  // Read an integer input from the user and store it in the variable n
        
        if (n % 2 == 0) {  // Check if the number n is even
            System.out.println(n / 2);  // If n is even, print half of n
        } else {  // If n is not even
            System.out.println((n / 2) + 1);  // Print half of n plus one
        }
        
        scanner.close();  // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
