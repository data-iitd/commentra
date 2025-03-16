import java.util.Scanner;

public class Main {
    // Initialize a new scanner to read from standard input
    private static final Scanner sc = new Scanner(System.in);

    // Function to read an integer from input
    private static int ri() {
        return sc.nextInt(); // Read the next integer from input
    }

    // Function to calculate the average of an array of double numbers
    private static double ave(double[] s) {
        double sum = 0;
        for (double v : s) { // Iterate over each value in the array
            sum += v; // Accumulate the sum of the values
        }
        return sum / s.length; // Return the average
    }

    // Function to calculate the absolute difference between two double numbers
    private static double diff(double a, double b) {
        return Math.abs(a - b); // Return the absolute difference
    }

    public static void main(String[] args) {
        int n = ri(); // Read the number of elements
        double[] a = new double[n]; // Create an array to hold the double numbers
        for (int i = 0; i < n; i++) {
            a[i] = ri(); // Read each integer and store it as double
        }

        // Calculate the average of the numbers
        double average = ave(a);

        // Initialize variables to track the minimum difference and the corresponding index
        double minDiff = Double.MAX_VALUE;
        int ansIndex = -1;
        for (int i = 0; i < a.length; i++) { // Iterate over the array to find the closest value to the average
            double currentDiff = diff(a[i], average); // Calculate the difference between the current value and the average
            if (currentDiff < minDiff) { // Check if the current difference is less than the minimum difference found so far
                minDiff = currentDiff; // Update the minimum difference
                ansIndex = i; // Update the index of the closest value
            }
        }
        // Print the index of the value closest to the average
        System.out.println(ansIndex);
    }
}

// <END-OF-CODE>
