import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        char B, OUT; // Declare two character variables B (input) and OUT (output)
        
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        B = scanner.next().charAt(0); // Read a character input from the user
        
        // Determine the output character based on the input character
        if (B == 'A') 
            OUT = 'T'; // If input is 'A', output 'T'
        else if (B == 'T') 
            OUT = 'A'; // If input is 'T', output 'A'
        else if (B == 'C') 
            OUT = 'G'; // If input is 'C', output 'G'
        else 
            OUT = 'C'; // For any other input, output 'C'
        
        // Output the result to the console
        System.out.println(OUT); // Print the output character

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
