import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Input the number of elements (n)
        List<Double> arr = new ArrayList<>();  // Input the array elements

        for (int i = 0; i < n; i++) {
            arr.add(scanner.nextDouble());
        }

        // Extract fractional parts and sort them
        List<Double> fractionalParts = new ArrayList<>();
        for (Double x : arr) {
            double fractionalPart = x - Math.floor(x);
            if (fractionalPart != 0) {
                fractionalParts.add(fractionalPart);
            }
        }

        Collections.sort(fractionalParts);

        // Calculate the number of elements to be added to make the total number of elements equal to 2 * n
        int o = 2 * n - fractionalParts.size();

        // Sum of the sorted fractional parts
        double arrSum = fractionalParts.stream().mapToDouble(Double::doubleValue).sum();

        // Initialize the result variable to a very large number
        double res = 2e9;

        // Iterate to find the best position
        for (int i = 0; i <= n; i++) {
            if (i + o >= n) {
                res = Math.min(res, Math.abs(i - arrSum));
            }
        }

        // Print the result with three decimal places
        System.out.printf("%.3f\n", res);
    }
}
