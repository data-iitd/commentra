import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // The main method is the entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int x; // Declare an integer variable x
        x = scanner.nextInt(); // Take an integer input from the user and store it in x
        System.out.println(x * x * x); // Output the cube of the input value x
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
