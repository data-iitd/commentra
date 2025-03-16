import java.util.Scanner;  // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int n = scanner.nextInt();  // Read the first integer
        int x = scanner.nextInt();  // Read the second integer
        int min = scanner.nextInt();  // Read the third integer
        x -= min;  // Subtract the minimum value from x

        for (int i = 1; i < n; i++) {  // Start a loop from 1 to n-1
            int m = scanner.nextInt();  // Read the next integer
            x -= m;  // Subtract the current integer from x
            if (min > m) {  // Check if the current integer is less than the current min
                min = m;  // Update min to the current integer if true
            }
        }
        System.out.println(n + x / min);  // Print the result
        scanner.close();  // Close the scanner
    }
}

// <END-OF-CODE>
