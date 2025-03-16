import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char B, OUT; // Declare two character variables B (input) and OUT (output)
        
        // Read a character input from the user
        B = sc.next().charAt(0);
        
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
