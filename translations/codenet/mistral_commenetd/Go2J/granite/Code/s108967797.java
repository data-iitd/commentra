

import java.util.Scanner;

public class s108967797{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of elements in the array from standard input
        int n = sc.nextInt();

        // Allocate memory for an array of float64 numbers with the given size
        double[] a = new double[n];

        // Read each element of the array from standard input and store it in the corresponding index
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextDouble(); // Read a double from standard input
        }
        // Print the array for debugging purposes (uncomment this line if needed)
        // System.out.println(Arrays.toString(a));

        // Calculate the average of the array elements
        double ave = ave(a);

        // Initialize variables to store the minimum difference and the index of the element with the minimum difference
        double minDiff = Double.MAX_VALUE;
        int ansIndex = -1;

        // Iterate through each element of the array and find the one with the minimum difference from the average
        for (int i = 0; i < n; i++) {
            double diff = Math.abs(a[i] - ave); // Calculate the absolute difference between the current element and the average
            if (diff < minDiff) { // Check if the difference is smaller than the current minimum difference
                minDiff = diff; // If so, update the minimum difference
                ansIndex = i; // and the index of the answer
            }
        }

        // Print the index of the element with the minimum difference from the average
        System.out.println(ansIndex);

        sc.close(); // Close the scanner
    }

    // Function to calculate the average of a slice of float64 numbers
    public static double ave(double[] s) {
        double sum = 0; // Initialize a variable to store the sum of numbers in the slice
        for (double v : s) { // Iterate through each number in the slice
            sum += v; // Add the current number to the sum
        }
        return sum / s.length; // Calculate and return the average
    }

}

// End of the code