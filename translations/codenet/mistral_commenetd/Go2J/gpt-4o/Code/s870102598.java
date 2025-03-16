import java.util.Scanner;

public class Main {
    // Define the main method as the entry point of our program
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Declare and initialize three integer variables "a", "b", and "c"
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        
        // Check if the value of "c" is within the range of "a" and "b"
        if (c >= a && c <= b) {
            // If the condition is true, print "Yes" to the standard output
            System.out.println("Yes");
        } else {
            // If the condition is false, print "No" to the standard output
            System.out.println("No");
        }
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
