import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input the number of elements (n)
        int n = scanner.nextInt();
        double[] arr = new double[n];
        
        // Input the array elements
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextDouble();
        }
        
        // Extract fractional parts
        double[] fractionalParts = Arrays.stream(arr)
                                         .map(x -> x - (int) x)
                                         .filter(x -> x != 0)
                                         .toArray();
        
        // Sort the fractional parts
        Arrays.sort(fractionalParts);
        
        // Calculate the number of elements to be added to make the total number of elements equal to 2 * n
        int o = 2 * n - fractionalParts.length;
        
        // Sum of the sorted fractional parts
        double arrSum = Arrays.stream(fractionalParts).sum();
        
        // Initialize the result variable to a very large number
        double res = 2e9;
        
        // Iterate to find the best position
        for (int i = 0; i <= n; i++) {
            if (i + o >= n) {
                res = Math.min(res, Math.abs(i - arrSum));
            }
        }
        
        // Print the result with three decimal places
        System.out.printf("%.3f%n", res);
        
        scanner.close();
    }
}
// <END-OF-CODE>
