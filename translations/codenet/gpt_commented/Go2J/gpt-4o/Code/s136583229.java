import java.util.Scanner; // Importing the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int data = scanner.nextInt(); // Read an integer value from standard input and store it in 'data'
        
        int result = data * data * data; // Calculate the cube of the input value
        System.out.println(result); // Print the result to standard output
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
