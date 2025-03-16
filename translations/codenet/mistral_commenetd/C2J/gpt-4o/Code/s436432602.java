import java.util.Scanner;

public class SubsetSum {

    // Function to run the logic of the program
    public static void run() {
        // Declare variables
        int n, k;

        // Read input values of n and k from the user
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array and the target sum: ");
        n = scanner.nextInt();
        k = scanner.nextInt();

        // Declare an array of size n to store the elements of the array
        int[] a = new int[n];

        // Read the elements of the array from the user
        System.out.print("Enter " + n + " integers: ");
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Declare a dynamic array of size k+1 to store the dp values
        int[] dp = new int[k + 1];

        // Initialize all dp values as false initially
        for (int i = 0; i <= k; i++) {
            dp[i] = 0;
        }

        // Calculate the dp values for all sums from 1 to k
        for (int i = 1; i <= k; i++) {
            int win = 0;

            // Check if there exists a subset of sum i in the given array a[]
            for (int j = 0; j < n && a[j] <= i; j++) {
                // If a[j] can be included in the subset, then check for the next element
                if (dp[i - a[j]] == 1) {
                    win = 1;
                    break;
                }
            }

            // Update the dp value for the current sum i
            dp[i] = win;
        }

        // Print the result based on the dp value for the target sum k
        System.out.print("The target sum " + k + " is ");
        if (dp[k] == 1) {
            System.out.println("First"); // Target sum is a subset of given array
        } else {
            System.out.println("Second"); // Target sum is not a subset of given array
        }

        // Close the scanner
        scanner.close();
    }

    // Main function to call the run function
    public static void main(String[] args) {
        // Call the run function to execute the logic
        run();
    }
}

// <END-OF-CODE>
