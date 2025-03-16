import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read an integer input for the number of elements
        int n = sc.nextInt();

        // Read a line of space-separated floats and convert them to a list of floats
        List<Float> arr = new ArrayList<Float>();
        for (int i = 0; i < n; i++) {
            arr.add(sc.nextFloat());
        }

        // Calculate the fractional parts of the elements, excluding whole numbers
        arr = arr.stream().filter(x -> x - (int) x!= 0).sorted().collect(Collectors.toList());

        // Calculate the number of whole numbers that can be added to the fractional parts
        int o = 2 * n - arr.size();

        // Calculate the sum of the fractional parts
        float arr_sum = arr.stream().reduce(0.0f, (x, y) -> x + y);

        // Initialize the result with a large number
        float res = 2e9f;

        // Iterate through possible counts of fractional parts used
        for (int i = 0; i <= n; i++) {
            // Check if the current count of fractional parts plus whole numbers is sufficient
            if (i + o >= n) {
                // Update the result with the minimum difference found
                res = Math.min(res, Math.abs(i - arr_sum));
            }
        }

        // Print the result formatted to three decimal places
        System.out.printf("%.3f", res);
    }
}

