import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        long sum = 0; // Initialize sum to 0
        int m, n, min = Integer.MAX_VALUE, max = Integer.MIN_VALUE; // Declare and initialize variables
        
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of integers to be input from the user
        n = scanner.nextInt();
        
        // Iterate through each integer input
        for (int i = 0; i < n; i++) {
            m = scanner.nextInt(); // Read an integer input and assign it to m
            sum += m; // Add the current integer input to the sum
            
            // Update min and max values if the current input is smaller or larger
            if (min > m) {
                min = m; // Set min to the current input if it's smaller
            }
            if (max < m) {
                max = m; // Set max to the current input if it's larger
            }
        }
        
        // Print the minimum value, maximum value, and sum of the input integers
        System.out.printf("%d %d %d\n", min, max, sum);
        
        scanner.close();
    }
}
// <END-OF-CODE>
