import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements
        int[] a = new int[100000];
        int cnt = 1;
        boolean isup;
        boolean issame = false;

        // Step 1: Reading Input
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt(); // Read the elements into the array
        }

        // Step 2: Initialization and Condition Check
        if (a[0] < a[1]) {
            isup = true; // Set isup to true if the first two elements indicate an increasing trend
        } else if (a[0] > a[1]) {
            isup = false; // Set isup to false if the first two elements indicate a decreasing trend
        } else {
            issame = true; // Set issame to true if the first two elements are the same
        }

        // Step 3: Loop Through Elements
        for (int i = 1; i < n - 1; i++) {
            if (issame) {
                if (a[i] != a[i + 1]) {
                    issame = false; // If the sequence is not consistent, reset issame and set the new trend
                    if (a[i] < a[i + 1]) {
                        isup = true;
                    } else {
                        isup = false;
                    }
                }
            } else {
                if (isup && a[i] <= a[i + 1]) {
                    // Continue if the current trend is increasing and the next element is greater or equal
                } else if (!isup && a[i] >= a[i + 1]) {
                    // Continue if the current trend is decreasing and the next element is less or equal
                } else {
                    if (i + 2 < n) {
                        if (a[i + 1] < a[i + 2]) {
                            isup = true; // Update the trend if the next element indicates a change
                        } else if (a[i + 1] > a[i + 2]) {
                            isup = false;
                        } else {
                            issame = true;
                        }
                        cnt++; // Increment the count for a new segment
                    } else {
                        cnt++; // Increment the count for the last segment
                        break;
                    }
                }
            }
        }

        // Step 4: Output the Result
        System.out.println(cnt); // Print the count of segments
        scanner.close();
    }
}
// <END-OF-CODE>
