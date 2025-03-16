
import java.util.Scanner;

public class s682653189{
    public static void main(String[] args) {
        // Declare a variable to hold the input string
        String s;
        
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read a string input from the user
        s = scanner.nextLine();
        
        // Loop through each character in the string
        for (int i = 0; i < s.length(); i++) {
            // Print 'x' for each character in the input string
            System.out.print("x");
        }
        
        // Print a newline after printing all 'x's
        System.out.println("");
    }
}
