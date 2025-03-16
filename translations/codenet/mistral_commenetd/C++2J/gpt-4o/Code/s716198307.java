import java.util.Scanner;

public class Main {
    // The main function from where the execution begins
    public static void main(String[] args) {
        // Declare variables
        int n;          // Number of elements in the array
        double avg = 0; // Average of the elements in the array
        double s;       // Difference between the first element and the average
        int ans = 0;    // Index of the element with the maximum difference from the average

        // Initialize variables
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt(); // Read the number of elements from the standard input
        int[] a = new int[100]; // Declare an array of size 100

        // Calculate the average of the elements in the array
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt(); // Read an element from the standard input and store it in the array
            avg += a[i]; // Add the current element to the sum of all elements
        }

        // Calculate the average and divide it by the number of elements
        avg /= n;

        // Initialize the difference between the first element and the average
        s = Math.abs(a[0] - avg);

        // Find the index of the element with the maximum difference from the average
        for (int i = 1; i < n; i++) {
            if (s > Math.abs(a[i] - avg)) { // If the current difference is greater than the previous difference
                s = Math.abs(a[i] - avg); // Update the difference
                ans = i; // Update the index
            }
        }

        // Print the index of the element with the maximum difference from the average
        System.out.println(ans);

        // Terminate the program
        scanner.close();
    }
}
// <END-OF-CODE>
