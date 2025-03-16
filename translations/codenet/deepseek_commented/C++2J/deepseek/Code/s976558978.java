public class Main {
    public static void main(String[] args) {
        // Read input values
        int a = readi();
        int b = readi();

        // Check if a is less than b
        if (a < b) {
            // Print a b times
            for (int i = 0; i < b; i++) {
                System.out.print(a);
            }
            System.out.println(); // New line
        } else {
            // Print b a times
            for (int i = 0; i < a; i++) {
                System.out.print(b);
            }
            System.out.println(); // New line
        }
    }

    // Dummy implementations for the readi function and other utility functions
    private static int readi() {
        // Implement the logic to read an integer from standard input
        return 0; // Placeholder
    }

