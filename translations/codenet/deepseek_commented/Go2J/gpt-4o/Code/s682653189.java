import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a string variable to store the input
        Scanner scanner = new Scanner(System.in);
        String s;
        
        // Read a string input from the user and store it in `s`
        s = scanner.nextLine();
        
        // Iterate over each character in the string `s` and print 'x' for each character
        for (int i = 0; i < s.length(); i++) {
            System.out.print("x");
        }
        
        // Print a newline character to move to the next line
        System.out.println("");
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
