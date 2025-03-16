import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array
        int n = scanner.nextInt();
        // Read the size of the subarray to be summed
        int a = scanner.nextInt();
        int sum = 0; // Initialize the sum variable to zero
        int[] s = new int[n]; // Declare an array of size n to store the input elements

        // Read the elements of the array from the user
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextInt(); // Read the i-th element of the array
        }

        // Sort the array in ascending order
        Arrays.sort(s); // Sort the array using the sort function from the Arrays library

        // Calculate the sum of the last 'a' elements of the sorted array
        for (int i = n - 1; i > n - a - 1; i--) {
            sum += s[i]; // Add the current element to the sum
        }

        // Print the result
        System.out.println(sum); // Print the sum of the last 'a' elements
    }
}
