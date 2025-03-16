import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements
        double[] a = new double[n]; // Create an array to hold the float64 numbers
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextDouble(); // Read each double value
        }

        // Calculate the average of the numbers
        double sum = 0;
        for (double v : a) {
            sum += v;
        }
        double ave = sum / n;

        // Initialize variables to track the minimum difference and the corresponding index
        double minDiff = Double.MAX_VALUE;
        int ansIndex = -1;
        for (int i = 0; i < n; i++) {
            double diff = Math.abs(a[i] - ave); // Calculate the absolute difference
            if (diff < minDiff) { // Check if the current difference is less than the minimum difference found so far
                minDiff = diff; // Update the minimum difference
                ansIndex = i; // Update the index of the closest value
            }
        }
        // Print the index of the value closest to the average
        System.out.println(ansIndex);
    }
}
