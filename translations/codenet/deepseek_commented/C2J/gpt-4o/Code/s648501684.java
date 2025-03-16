import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to store the input values
        long n, k, q;

        // Create a Scanner object for reading input
        Scanner scanner = new Scanner(System.in);

        // Read three long integers from the standard input
        n = scanner.nextLong();
        k = scanner.nextLong();
        q = scanner.nextLong();

        // Declare an array of size n initialized to 0
        int[] arr = new int[(int) n + 1]; // +1 to accommodate 1-based indexing
        for (long i = 1; i <= n; i++) {
            arr[(int) i] = 0; // Initialize each element to 0
        }

        // Read q integers and increment the corresponding index in the array arr
        for (long i = 0; i < q; i++) {
            long temp = scanner.nextLong();
            arr[(int) temp] += 1;
        }

        // Check if the value at each index in arr is greater than q-k
        for (long i = 1; i <= n; i++) {
            if (arr[(int) i] > (q - k)) {
                System.out.println("Yes"); // Print "Yes" if the condition is met
            } else {
                System.out.println("No"); // Print "No" otherwise
            }
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
