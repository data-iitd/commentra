import java.util.Scanner;

public class Main {
    // Initialize a new scanner for reading input from stdin
    private static final Scanner sc = new Scanner(System.in);

    // Function to read an integer from standard input
    private static int ri() {
        return sc.nextInt(); // Read the next integer from input
    }

    // Function to calculate the average of an array of double numbers
    private static double ave(double[] s) {
        double sum = 0; // Initialize a variable to store the sum of numbers in the array
        for (double v : s) { // Iterate through each number in the array
            sum += v; // Add the current number to the sum
        }
        return sum / s.length; // Calculate and return the average
    }

    // Function to calculate the difference between two double numbers
    private static double diff(double a, double b) {
        return Math.abs(a - b); // Return the absolute difference
    }

    // Main function
    public static void main(String[] args) {
        // Read the number of elements in the array from standard input
        int n = ri();

        // Allocate memory for an array of double numbers with the given size
        double[] a = new double[n];

        // Read each element of the array from standard input and store it in the corresponding index
        for (int i = 0; i < n; i++) {
            a[i] = ri(); // Read an integer from standard input and store it as a double
        }

        // Calculate the average of the array elements
        double average = ave(a);

        // Initialize variables to store the minimum difference and the index of the element with the minimum difference
        double minDiff = Double.MAX_VALUE;
        int ansIndex = -1;

        // Iterate through each element of the array and find the one with the minimum difference from the average
        for (int i = 0; i < a.length; i++) {
            double currentDiff = diff(a[i], average); // Calculate the difference between the current element and the average
            if (currentDiff < minDiff) { // Check if the difference is smaller than the current minimum difference
                minDiff = currentDiff; // If so, update the minimum difference
                ansIndex = i; // and the index of the answer
            }
        }

        // Print the index of the element with the minimum difference from the average
        System.out.println(ansIndex);
    }
}
// <END-OF-CODE>
