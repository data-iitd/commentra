import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables for the number of elements and an array for dynamic array allocation
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] data = new int[n];

        // Read 'n' integers from user input into the allocated array
        for (int i = 0; i < n; i++) {
            data[i] = scanner.nextInt();
        }

        // Initialize variables to find the maximum value and its index
        int max = 0, index = -1;

        // Find the maximum value in the array and its index
        for (int i = 0; i < n; i++) {
            if (data[i] > max) {
                max = data[i];
                index = i;
            }
        }

        // Initialize a variable to calculate the sum of all elements except the maximum
        int sum = 0;

        // Calculate the sum of all elements excluding the maximum value
        for (int i = 0; i < n; i++) {
            if (i != index) {
                sum += data[i];
            }
        }

        // Compare the sum of the other elements with the maximum value and print the result
        if (sum > max) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
