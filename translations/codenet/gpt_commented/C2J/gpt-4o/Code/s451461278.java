import java.util.Scanner;

public class Sorting {

    static final int MAX = 100000;

    // Function prototypes for partitioning and sorting
    static int partition(char[] C, int[] A, int p, int r) {
        int i, j;
        char tmpC, x;
        int tmpN, y;

        // Choose the last element as pivot
        x = C[r];
        y = A[r];
        i = p - 1;

        // Rearrange elements based on the pivot
        for (j = p; j < r; j++) {
            if (A[j] <= y) {
                i = i + 1;
                // Swap elements to partition the array
                tmpN = A[j];
                tmpC = C[j];
                A[j] = A[i];
                C[j] = C[i];
                A[i] = tmpN;
                C[i] = tmpC;
            }
        }

        // Place the pivot in the correct position
        tmpN = A[i + 1];
        tmpC = C[i + 1];
        A[i + 1] = A[r];
        C[i + 1] = C[r];
        A[r] = tmpN;
        C[r] = tmpC;

        return i + 1; // Return the pivot index
    }

    static void quicksort(char[] C, int[] A, int p, int r) {
        // Base case for recursion
        if (p < r) {
            int q = partition(C, A, p, r); // Partition the array
            quicksort(C, A, p, q - 1); // Recursively sort the left subarray
            quicksort(C, A, q + 1, r); // Recursively sort the right subarray
        }
    }

    static void merge(char[] MC, int[] MN, int left, int mid, int right) {
        int n1 = mid - left + 1; // Size of left subarray
        int n2 = right - mid; // Size of right subarray
        int[] LN = new int[n1 + 1]; // Left subarray for integers
        int[] RN = new int[n2 + 1]; // Right subarray for integers
        char[] LC = new char[n1 + 1]; // Left subarray for characters
        char[] RC = new char[n2 + 1]; // Right subarray for characters

        // Copy data to temporary arrays
        for (int i = 1; i <= n1; i++) {
            LN[i] = MN[left + i - 1];
            LC[i] = MC[left + i - 1];
        }

        for (int i = 1; i <= n2; i++) {
            RN[i] = MN[mid + i];
            RC[i] = MC[mid + i];
        }

        // Sentinel values for merging
        LN[n1] = Integer.MAX_VALUE;
        RN[n2] = Integer.MAX_VALUE;

        int i = 1; // Index for left subarray
        int j = 1; // Index for right subarray

        // Merge the temporary arrays back into the original arrays
        for (int k = left; k <= right; k++) {
            if (LN[i] <= RN[j]) {
                MN[k] = LN[i];
                MC[k] = LC[i++];
            } else {
                MN[k] = RN[j];
                MC[k] = RC[j++];
            }
        }
    }

    static void mergeSort(char[] MC, int[] MN, int left, int right) {
        int mid;

        // Base case for recursion
        if (left < right) {
            mid = (left + right) / 2; // Find the midpoint
            mergeSort(MC, MN, left, mid); // Recursively sort the left half
            mergeSort(MC, MN, mid + 1, right); // Recursively sort the right half
            merge(MC, MN, left, mid, right); // Merge the sorted halves
        }
    }

    public static void main(String[] args) {
        // Declare arrays for storing values and characters
        int[] A = new int[MAX + 1]; // Array for integer values
        char[] C = new char[MAX + 1]; // Array for characters
        char[] MC = new char[MAX + 1]; // Array for characters for merge sort
        int[] MN = new int[MAX + 1]; // Array for integer values for merge sort

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements

        // Read character and integer pairs into arrays
        for (int i = 1; i <= n; i++)
            C[i] = scanner.next().charAt(0); // Read character
            A[i] = scanner.nextInt(); // Read integer

        // Copy original arrays to auxiliary arrays for merge sort
        for (int i = 1; i <= n; i++) {
            MC[i] = C[i];
            MN[i] = A[i];
        }

        // Perform merge sort on the auxiliary arrays
        mergeSort(MC, MN, 1, n);

        // Perform quicksort on the original arrays
        quicksort(C, A, 1, n);

        // Check if the sorting is stable by comparing original and sorted arrays
        int count = 0; // Counter for stable sorting check
        for (int i = 1; i <= n; i++) {
            if (MN[i] == A[i] && MC[i] == C[i])
                count++;
        }

        // Output stability result
        if (count == n)
            System.out.println("Stable");
        else
            System.out.println("Not stable");

        // Print the sorted character and integer pairs
        for (int i = 1; i <= n; i++)
            System.out.println(C[i] + " " + A[i]);

        scanner.close();
    }
}

// <END-OF-CODE>
