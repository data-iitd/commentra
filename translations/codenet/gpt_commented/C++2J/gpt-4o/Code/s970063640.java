import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements from user input
        int n = scanner.nextInt();

        // Read the number of largest elements to sum from user input
        int a = scanner.nextInt();

        // Initialize a variable to hold the sum of the largest elements
        int sum = 0;

        // Declare an array to hold the elements
        int[] s = new int[n];

        // Read the elements into the array from user input
        for (int i = 0; i < n; i++) {
            s[i] = scanner.nextInt();
        }

        // Sort the array in non-decreasing order
        Arrays.sort(s);

        // Sum the largest 'a' elements from the sorted array
        for (int i = n - 1; i > n - a - 1; i--) {
            sum += s[i];
        }

        // Output the calculated sum of the largest 'a' elements
        System.out.println(sum);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
