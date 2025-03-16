import java.util.Scanner;

public class Main {
    // Define a large constant for infinity
    static final long INF = (long) 1e20;

    // Define a modulus value commonly used in competitive programming
    static final int MOD = (int) 1e9 + 7;

    // Main function to execute the core logic of the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read four integers from input
        long a = scanner.nextLong();
        long b = scanner.nextLong();
        long c = scanner.nextLong();
        long d = scanner.nextLong();
        
        // Calculate the maximum value from the products of the pairs and print it
        System.out.println(Math.max(Math.max(a * c, b * d), Math.max(a * d, b * c)));
        
        scanner.close();
    }
}

// <END-OF-CODE>
