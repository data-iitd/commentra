
import java.util.Scanner; // Import the Scanner class from the java.util package

public class s074799395{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the console
        char B = scanner.nextLine().charAt(0); // Read a character input from the user and store it in the variable B
        char OUT; // Declare a character variable OUT to store the output character
        
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
        System.out.println(OUT); // Print the output character to the console
        
        scanner.close(); // Close the Scanner object to release system resources
    }
}
