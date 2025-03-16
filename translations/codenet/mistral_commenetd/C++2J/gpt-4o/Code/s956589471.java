import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        // Declare and initialize six integer variables
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();
        int e = scanner.nextInt();
        int k = scanner.nextInt();

        // Perform a simple condition check using the relational operator <=
        if (e - a <= k) {
            System.out.println("Yay!"); // If the condition is true, print "Yay!"
        } else {
            System.out.println(":("); // If the condition is false, print ":("
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
