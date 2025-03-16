import java.util.Scanner;

public class Main {
    // Function to read a single integer from input
    public static int nextInt() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextInt();
    }

    // Function to read a list of integers from input
    public static int[] nextInts() {
        Scanner scanner = new Scanner(System.in);
        String[] parts = scanner.nextLine().split(" ");
        int[] result = new int[parts.length];
        for (int i = 0; i < parts.length; i++) {
            result[i] = Integer.parseInt(parts[i]);
        }
        return result;
    }

    public static void main(String[] args) {
        // Read the number of iterations or elements
        int n = nextInt();

        // Initialize a counter for odd indices
        int t = 0;

        // Loop through the range of n
        for (int i = 0; i < n; i++) {
            // Check if the current index (i + 1) is odd
            if ((i + 1) % 2 != 0) {
                t += 1; // Increment the counter for odd indices
            }
        }

        // Calculate and print the ratio of odd indices to total elements
        System.out.println((double) t / n);
    }
}
