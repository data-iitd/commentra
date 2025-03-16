import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements from the user
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();

        // Allocate memory for the array of size 'n'
        int[] data = new int[n];

        // Read each element of the array from the user
        for (int i = 0; i < n; i++) {
            System.out.print("Enter element " + (i + 1) + ": ");
            data[i] = scanner.nextInt();
        }

        int max = 0; // Initialize 'max' variable to store the maximum element
        int index = -1; // Initialize 'index' variable to store the index of the maximum element

        // Find the maximum element and its index
        for (int i = 0; i < n; i++) {
            if (data[i] > max) {
                max = data[i];
                index = i;
            }
        }

        int a = 0; // Initialize 'a' variable to store the sum of all elements except the maximum

        // Calculate the sum of all elements except the maximum
        for (int i = 0; i < n; i++) {
            if (i != index) {
                a += data[i];
            }
        }

        // Check if the sum of all elements except the maximum is greater than the maximum
        if (a > max) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
