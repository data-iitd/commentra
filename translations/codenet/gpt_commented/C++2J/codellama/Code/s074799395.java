import java.util.Scanner; // Import the Scanner class

public class Main {
    public static void main(String[] args) {
        char B, OUT; // Declare two character variables B (input) and OUT (output)
        
        // Create a Scanner object to read input from the command line
        Scanner input = new Scanner(System.in);
        
        // Read a character input from the user
        B = input.next().charAt(0);
        
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
        System.out.println(OUT);
    }
}
