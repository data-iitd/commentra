import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Set the recursion limit (not directly applicable in Java like in Python)
        // Java has a default stack size, and you can set it via JVM options if needed.

        // Create a scanner for input
        Scanner scanner = new Scanner(System.in);

        // Read input for two numbers 'a' and 'b'
        String sa = scanner.next();
        String sb = scanner.next();
        
        // Convert 'a' to an integer
        int a = Integer.parseInt(sa);
        
        // Convert 'b' to an integer after scaling it by 100
        int b = (int) (Double.parseDouble(sb) * 100 + 0.1);

        // Calculate the product of 'a' and 'b' and print the result
        System.out.println(a * b / 100);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
