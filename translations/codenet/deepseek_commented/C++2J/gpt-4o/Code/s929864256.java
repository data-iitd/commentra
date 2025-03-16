import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        long a = scanner.nextLong(); // Read the first long integer
        long b = scanner.nextLong(); // Read the second long integer

        // Compute the maximum value among a+b, a-b, and a*b
        long result = Math.max(a + b, Math.max(a - b, a * b)); // Calculate the maximum value

        System.out.println(result); // Print the maximum value

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
