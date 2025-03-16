public class Main {
    public static void main(String[] args) {
        // Declare variables to hold input values and results
        int A, B, C, D, E, max;

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read two integers from user input
        A = scanner.nextInt();
        B = scanner.nextInt();

        // Calculate the sum, difference, and product of A and B
        C = A + B;  // Sum of A and B
        D = A - B;  // Difference of A and B
        E = A * B;  // Product of A and B

        // Initialize max with the value of C (sum)
        max = C;

        // Compare max with D (difference) and update if D is greater
        if (max < D) {
            max = D;
        }

        // Compare max with E (product) and update if E is greater
        if (max < E) {
            max = E;
        }

        // Print the maximum value among sum, difference, and product
        System.out.println(max);

        // Close the scanner to free up resources
        scanner.close();
    }
}
