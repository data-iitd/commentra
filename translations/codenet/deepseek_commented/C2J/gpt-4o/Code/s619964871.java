import java.util.Scanner;

public class TheNumberOfInversionsFix {
    private static final long UNKO = (long) 1e12;

    // Function to merge two subarrays and count inversions
    private static long sort(long[] a, int left, int middle, int right) {
        long[] lArr = new long[middle - left + 1];
        long[] rArr = new long[right - middle + 1];
        long cnt = 0;

        // Copy elements into temporary arrays
        for (int i = 0; i < middle - left; i++) {
            lArr[i] = a[i + left];
        }
        for (int i = 0; i < right - middle; i++) {
            rArr[i] = a[i + middle];
        }

        // Sentinel values to simplify merging
        lArr[middle - left] = UNKO;
        rArr[right - middle] = UNKO;

        int l = 0, r = 0;

        // Merge the two subarrays while counting inversions
        for (int i = 0; i < right - left; i++) {
            if (lArr[l] <= rArr[r]) {
                a[left + i] = lArr[l++];
            } else {
                a[left + i] = rArr[r++];
                cnt += middle - left - l;
            }
        }
        return cnt;
    }

    // Recursive function to count inversions in the array
    private static long merge(long[] a, int left, int right) {
        if (left + 1 < right) {
            int middle = (left + right) / 2;
            // Recursively count inversions in the left and right halves
            long x1 = merge(a, left, middle);
            long x2 = merge(a, middle, right);
            // Merge the two halves and count inversions in the merge step
            long x3 = sort(a, left, middle, right);
            return x1 + x2 + x3;
        } else {
            return 0;
        }
    }

    // Main function to read input, count inversions, and print the result
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the size of the array
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong(); // Read the elements of the array
        }
        System.out.println(merge(a, 0, n)); // Count and print the number of inversions
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
