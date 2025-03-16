import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input for the number of elements
        int n = scanner.nextInt();
        
        // Read a line of space-separated floats and convert them to an array of floats
        float[] arr = new float[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextFloat();
        }
        
        // Calculate the fractional parts of the elements, excluding whole numbers
        float[] fractionalParts = Arrays.stream(arr)
                                         .map(x -> x - (int)x)
                                         .filter(x -> x != 0)
                                         .toArray();
        
        // Sort the fractional parts
        Arrays.sort(fractionalParts);
        
        // Calculate the number of whole numbers that can be added to the fractional parts
        int o = 2 * n - fractionalParts.length;
        
        // Calculate the sum of the fractional parts
        float arrSum = 0;
        for (float f : fractionalParts) {
            arrSum += f;
        }
        
        // Initialize the result with a large number
        float res = 2e9f;
        
        // Iterate through possible counts of fractional parts used
        for (int i = 0; i <= n; i++) {
            // Check if the current count of fractional parts plus whole numbers is sufficient
            if (i + o >= n) {
                // Update the result with the minimum difference found
                res = Math.min(res, Math.abs(i - arrSum));
            }
        }
        
        // Print the result formatted to three decimal places
        System.out.printf("%.3f%n", res);
        
        scanner.close();
    }
}
// <END-OF-CODE>
