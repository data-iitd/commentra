public class Main {
    public static void main(String[] args) {
        // Read the number of elements
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();

        // Initialize a vector to store the input numbers
        java.util.ArrayList<Long> a = new java.util.ArrayList<>();
        // Read the input numbers into the vector
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextLong());
        }

        // Create a copy of the input vector to store absolute values
        java.util.ArrayList<Long> abs_a = new java.util.ArrayList<>(a);

        // Convert all elements in abs_a to their absolute values
        for (int i = 0; i < n; i++) {
            if (abs_a.get(i) < 0) {
                abs_a.set(i, -abs_a.get(i));
            }
        }

        // Initialize variables to calculate the sum of absolute values and find the minimum absolute value
        long ans = 0;
        long min = abs_a.get(0);
        // Iterate through the absolute values to calculate the total sum and find the minimum
        for (long e : abs_a) {
            ans += e; // Accumulate the sum of absolute values
            if (min > e) {
                min = e; // Update the minimum absolute value found
            }
        }

        // Count the number of negative numbers in the original array
        int num_negative = 0;
        for (long e : a) {
            if (e < 0) {
                num_negative++; // Increment count for each negative number
            }
        }

        // If the count of negative numbers is odd, adjust the total sum
        if (num_negative % 2 != 0) {
            ans -= min * 2; // Subtract twice the minimum absolute value from the total sum
        }

        // Output the final result
        System.out.println(ans);
    }
}
