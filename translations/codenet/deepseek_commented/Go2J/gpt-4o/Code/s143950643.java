import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare an integer variable 'a'
        int a;
        
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer value from the standard input and assign it to 'a'
        a = scanner.nextInt();
        
        // Print the result of the expression 3 * a * a
        System.out.println(3 * a * a);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
