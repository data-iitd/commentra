import java.util.Scanner;  // Step 1: Import necessary classes

public class Main {  // Step 1: Define the main class

    public static void main(String[] args) {  // Step 1: Define the main method

        // Step 2: Declare necessary variables
        int[] a = new int[10000];
        int min, max, n;
        long sum = 0;

        // Step 3: Read the number of elements (n) from the user
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        // Step 4: Read the elements of the array from the user and calculate the sum
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
            sum += a[i];
        }

        // Step 5: Find the minimum and maximum values in the array
        max = min = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] > max) max = a[i];
            if (a[i] < min) min = a[i];
        }

        // Step 6: Print the minimum, maximum, and sum of the elements
        System.out.printf("%d %d %d\n", min, max, sum);

        scanner.close();  // Close the scanner
    }  // End of the main method
}  // End of the main class
// <END-OF-CODE>
