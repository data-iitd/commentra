import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two string variables s and t
        String s, t;
        
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read input from the user and store it in s and t
        s = scanner.next();
        t = scanner.next();
        
        // Print the concatenated result of t and s
        System.out.println(t + s);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
