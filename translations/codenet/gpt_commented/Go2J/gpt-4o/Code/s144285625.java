import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a scanner to read input from standard input
        Scanner sc = new Scanner(System.in);

        // Read the number of groups of three integers
        int n = sc.nextInt();

        // Initialize an array to hold 3*n integers
        int[] ar = new int[3 * n];

        // Populate the array with integers from input
        for (int i = 0; i < ar.length; i++) {
            ar[i] = sc.nextInt();
        }

        // Sort the array of integers in ascending order
        Arrays.sort(ar);

        // Initialize a variable to hold the sum of selected integers
        int sum = 0;

        // Calculate the sum of the second largest integer from each group of three
        for (int i = 0; i < n; i++) {
            sum += ar[3 * n - (i + 1) * 2]; // Select the second largest integer from the sorted array
        }

        // Print the final computed sum
        System.out.println(sum);
    }
}
// <END-OF-CODE>
