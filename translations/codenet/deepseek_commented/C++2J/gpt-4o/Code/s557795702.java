import java.util.Scanner; // Import the Scanner class for input operations.
import java.util.Arrays; // Import the Arrays class for array operations.

public class InversionCount {
    static final int INF = 0x3f3f3f3f; // Define a constant INF for initializing arrays.
    static long[] a; // Declare an array to store the elements.
    static long[] L; // Array to temporarily store the left half during merge.
    static long[] R; // Array to temporarily store the right half during merge.

    // Merge function: Merges two sorted halves of the array a from index left to right.
    static long merge(int left, int mid, int right) {
        int n1 = mid - left;
        int n2 = right - mid;
        long cnt = 0;

        for (int i = 0; i < n1; ++i) L[i] = a[left + i];
        for (int i = 0; i < n2; ++i) R[i] = a[mid + i];
        L[n1] = R[n2] = INF;

        int i = 0, j = 0;
        for (int k = left; k < right; ++k) {
            if (L[i] <= R[j]) {
                a[k] = L[i++];
            } else {
                a[k] = R[j++];
                cnt += n1 - i; // Count inversions
            }
        }
        return cnt;
    }

    // Merge sort function: Recursively divides the array into halves and sorts them using merge sort.
    static long mergesort(int left, int right) {
        long v1 = 0, v2 = 0, v3 = 0;
        if (left + 1 < right) {
            int mid = (left + right) / 2;
            v1 = mergesort(left, mid);
            v2 = mergesort(mid, right);
            v3 = merge(left, mid, right);
            return v1 + v2 + v3;
        }
        return 0;
    }

    // Main function: Reads the number of elements and the elements themselves, calls the merge sort function to sort the array and compute the number of inversions, and prints the number of inversions.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        a = new long[n];
        L = new long[n / 2 + 1]; // Temporary array for left half
        R = new long[n / 2 + 1]; // Temporary array for right half

        for (int i = 0; i < n; ++i) {
            a[i] = scanner.nextLong();
        }
        long ans = mergesort(0, n);
        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
