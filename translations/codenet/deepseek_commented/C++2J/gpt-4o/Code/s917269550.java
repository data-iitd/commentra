import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long x = scanner.nextLong();  // Read the first integer
        long y = scanner.nextLong();  // Read the second integer
        if (Math.abs(x - y) <= 1) {
            System.out.println("Brown");  // Check if the absolute difference is less than or equal to 1
        } else {
            System.out.println("Alice");  // Otherwise, print "Alice"
        }
        scanner.close();  // Close the scanner
    }
}

// <END-OF-CODE>
