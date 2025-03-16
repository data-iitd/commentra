import java.util.Scanner; // Importing the Scanner class for input operations
import java.util.stream.IntStream; // Importing IntStream for stream processing

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize Scanner object to read input
        int n = scanner.nextInt(); // Read the first integer input
        int x = scanner.nextInt(); // Read the second integer input
        print(x, n); // Call the print method with x and n as arguments
    }

    // Method to print based on the value of x and n
    public static void print(int x, int n) {
        int max = n * 2 - 1; // Calculate the maximum value based on n
        if (x == 1 || x == max) { // Check if x is at the edges
            System.out.println("No"); // Print "No" if x is 1 or max
            return; // Exit the method
        }
        System.out.println("Yes"); // Print "Yes" if x is within the valid range
        String sep = System.lineSeparator(); // Get the system's line separator
        String ans = IntStream.range(x + n - 1, x + n + max - 1) // Generate a stream of numbers
                .mapToObj(e -> (e % max + 1) + sep) // Map each number to the required format
                .collect(StringBuilder::new, StringBuilder::append, StringBuilder::append) // Collect into a StringBuilder
                .toString(); // Convert to a string
        System.out.println(ans); // Print the constructed string
    }
}
