import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input for the number of elements
        int n = scanner.nextInt();
        
        // Read a line of space-separated floats and convert them to a list of floats
        List<Double> arr = new ArrayList<>();
        for (String s : scanner.next().split(" ")) {
            arr.add(Double.parseDouble(s));
        }
        
        // Calculate the fractional parts of the elements, excluding whole numbers
        List<Double> fractionalParts = new ArrayList<>();
        for (Double x : arr) {
            if (x != (int) x) {
                fractionalParts.add(x - Math.floor(x));
            }
        }
        
        // Sort the fractional parts
        Collections.sort(fractionalParts);
        
        // Calculate the number of whole numbers that can be added to the fractional parts
        int o = 2 * n - fractionalParts.size();
        
        // Calculate the sum of the fractional parts
        double arrSum = fractionalParts.stream().mapToDouble(Double::doubleValue).sum();
        
        // Initialize the result with a large number
        double res = 2e9;
        
        // Iterate through possible counts of fractional parts used
        for (int i = 0; i <= n; i++) {
            // Check if the current count of fractional parts plus whole numbers is sufficient
            if (i + o >= n) {
                // Update the result with the minimum difference found
                res = Math.min(res, Math.abs(i - arrSum));
            }
        }
        
        // Print the result formatted to three decimal places
        System.out.printf("%.3f\n", res);
    }
}
