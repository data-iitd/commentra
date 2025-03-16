import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        int n, cnt = 0;
        int[] l = new int[2001];

        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements
        n = scanner.nextInt();

        // Input the elements into the array
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }

        // Sort the array using a simple bubble sort algorithm
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                // Swap elements if they are in the wrong order
                if (l[j] < l[i]) {
                    int tmp = l[i];
                    l[i] = l[j];
                    l[j] = tmp;
                }
            }
        }

        // Count the number of valid triplets (i, j, k) such that l[i] + l[j] > l[k]
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    // Check if the sum of two elements is greater than the third
                    if (l[i] + l[j] > l[k]) {
                        cnt++; // Increment count if the condition is satisfied
                    } else {
                        break; // Break if the condition is not satisfied (since array is sorted)
                    }
                }
            }
        }

        // Output the count of valid triplets
        System.out.println(cnt);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
