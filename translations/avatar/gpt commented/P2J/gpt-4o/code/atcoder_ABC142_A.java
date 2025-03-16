import java.util.Scanner;

public class Main {
    // Function to read a single integer from input
    public static int nextInt(Scanner scanner) {
        return scanner.nextInt();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of iterations or elements
        int n = nextInt(scanner);

        // Initialize a counter for odd indices
        int t = 0;

        // Loop through the range of n
        for (int i = 0; i < n; i++) {
            // Check if the current index (i + 1) is odd
            if ((i + 1) % 2 != 0) {
                t++;  // Increment the counter for odd indices
            }
        }

        // Calculate and print the ratio of odd indices to total elements
        System.out.println((double) t / n);

        scanner.close();
    }
}

// <END-OF-CODE>
