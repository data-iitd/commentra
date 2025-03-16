// Import necessary packages
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare and initialize variables
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] h = new int[100001];
        int max = -1;
        int flag = 0;

        // Read and process input
        for (int i = 0; i < n; i++) {
            // Read the next integer from standard input and store it in the array h
            h[i] = scanner.nextInt();

            // Update the maximum height if the current height is greater
            if (max < h[i]) max = h[i];

            // Check if the difference between the current height and maximum height is greater than or equal to 2
            if (max - h[i] >= 2) flag = 1;
        }

        // Check the value of the flag and print the appropriate message to the standard output
        if (flag == 1) System.out.println("No");
        else System.out.println("Yes");

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
