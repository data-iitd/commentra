import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a new scanner to read input from standard input
        Scanner sc = new Scanner(System.in);
        
        // Read the next line of input
        String s = sc.nextLine();
        
        // Calculate the difference between lowercase and uppercase letters
        int d = 'a' - 'A';
        
        // Iterate over each character in the input string
        for (char r : s.toCharArray()) {
            // Initialize a variable to hold the modified character
            char rr = r;
            
            // Check if the character is an uppercase letter
            if ('A' <= r && r <= 'Z') {
                // Convert uppercase to lowercase by adding the difference
                rr = (char) (r + d);
            } else if ('a' <= r && r <= 'z') {
                // Convert lowercase to uppercase by subtracting the difference
                rr = (char) (r - d);
            }
            
            // Print the modified character
            System.out.print(rr);
        }
        
        // Print a newline at the end of the output
        System.out.println();
        
        // Close the scanner
        sc.close();
    }
}

// <END-OF-CODE>
