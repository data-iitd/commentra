import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Take an integer input 'n' from the user
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Take 'n' floating point numbers as input and store them in a list 'arr'
        List<Double> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr.add(scanner.nextDouble());
        }

        // Filter out the integers from the list 'arr' and sort the remaining floating point numbers
        List<Double> filteredArr = new ArrayList<>();
        for (double x : arr) {
            double fractionalPart = x - (int) x;
            if (fractionalPart != 0) {
                filteredArr.add(fractionalPart);
            }
        }
        Collections.sort(filteredArr);

        // Calculate the length of the filtered list 'arr' and assign it to the variable 'o'
        int o = 2 * n - filteredArr.size();

        // Calculate the sum of all the floating point numbers in the list 'arr' and assign it to the variable 'arr_sum'
        double arrSum = 0;
        for (double value : filteredArr) {
            arrSum += value;
        }

        // Initialize the variable 'res' with a large integer value
        double res = 2e9;

        // Iterate through the range from 0 to n+1
        for (int i = 0; i <= n; i++) {
            // Check if the index 'i' plus the offset 'o' is greater than or equal to 'n'
            if (i + o >= n) {
                // Update the minimum value of 'res' with the absolute difference between 'i' and 'arr_sum'
                res = Math.min(res, Math.abs(i - arrSum));
            }
        }

        // Print the result with three decimal places
        System.out.printf("%.3f%n", res);
    }
}
// <END-OF-CODE>
