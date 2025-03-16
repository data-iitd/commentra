import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // The entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int a, b, c, count; // Declare variables a, b, c, and count
        a = scanner.nextInt(); // Read the first integer
        b = scanner.nextInt(); // Read the second integer
        c = scanner.nextInt(); // Read the third integer
        count = 0; // Initialize the count variable to zero

        // The following for loop iterates from the value of 'a' to the value of 'b'
        for (int i = a; i <= b; i++) {
            // Check if 'c' is divisible by 'i'
            if (c % i == 0)
                // If it is, increment the count variable
                count++;
        }

        // Print the value of 'count' to the standard output
        System.out.println(count);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
