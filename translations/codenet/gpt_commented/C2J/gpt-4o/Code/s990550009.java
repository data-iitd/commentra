import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        int n, cnt = 1; // n: number of elements, cnt: count of segments
        int[] a = new int[100000]; // a: array to store elements
        boolean isup; // Flag to indicate if the current segment is increasing
        boolean issame = false; // Flag to indicate if the current segment has the same values

        // Read the number of elements
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        
        // Read the elements into the array
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Determine the initial trend based on the first two elements
        if (a[0] < a[1]) {
            isup = true; // Initial trend is increasing
        } else if (a[0] > a[1]) {
            isup = false; // Initial trend is decreasing
        } else {
            issame = true; // Initial elements are the same
        }

        // Iterate through the array to count segments
        for (int i = 1; i < n - 1; i++) {
            // Handle the case where previous elements are the same
            if (issame) {
                if (a[i] != a[i + 1]) {
                    issame = false; // Found a different value, update flag
                    if (a[i] < a[i + 1]) {
                        isup = true; // New trend is increasing
                    } else {
                        isup = false; // New trend is decreasing
                    }
                }
            } else {
                // Check if the current trend is maintained
                if (isup && a[i] <= a[i + 1]) {
                    // Trend is increasing and maintained
                    // Do nothing
                } else if (!isup && a[i] >= a[i + 1]) {
                    // Trend is decreasing and maintained
                    // Do nothing
                } else {
                    // Trend has changed
                    if (i + 2 < n) {
                        // Determine the new trend based on the next element
                        if (a[i + 1] < a[i + 2]) {
                            isup = true; // New trend is increasing
                        } else if (a[i + 1] > a[i + 2]) {
                            isup = false; // New trend is decreasing
                        } else {
                            issame = true; // New elements are the same
                        }
                        cnt++; // Increment the segment count
                    } else {
                        cnt++; // Increment the segment count for the last element
                        break; // Exit the loop as we reached the end
                    }
                }
            }
        }

        // Output the total number of segments
        System.out.println(cnt);
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
