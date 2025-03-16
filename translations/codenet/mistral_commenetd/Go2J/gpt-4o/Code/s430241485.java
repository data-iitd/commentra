import java.util.Scanner; // Import the Scanner class for reading input

public class Main { // Define the Main class
    public static void main(String[] args) { // Define the main method, entry point of our program
        // Declare two variables, s and t, both of type String
        String s, t;

        // Create a Scanner object to read input from the standard input (keyboard)
        Scanner scanner = new Scanner(System.in);

        // Use the Scanner to read two strings from the input
        s = scanner.next();
        t = scanner.next();

        // Print the concatenated string of t and s
        System.out.println(t + s);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
