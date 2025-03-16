import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the Main class
    public static void main(String[] args) { // The main method is the entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for reading input
        int t, n; // Declare two integer variables: t for the user input and n for the number of items

        // The for loop runs 4 times, each time reading user input and processing it accordingly
        for (int i = 0; i < 4; i++) {
            t = scanner.nextInt(); // Read the first integer from the user: t
            n = scanner.nextInt(); // Read the second integer from the user: n

            // Check the value of t and process the input accordingly
            if (t == 1) {
                System.out.println(6000 * n); // If t is 1, print the result of multiplying n by 6000
            } else if (t == 2) {
                System.out.println(4000 * n); // If t is 2, print the result of multiplying n by 4000
            } else if (t == 3) {
                System.out.println(3000 * n); // If t is 3, print the result of multiplying n by 3000
            } else if (t == 4) {
                System.out.println(2000 * n); // If t is 4, print the result of multiplying n by 2000
            }
        }
        scanner.close(); // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
