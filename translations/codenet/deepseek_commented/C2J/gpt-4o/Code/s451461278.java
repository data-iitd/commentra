import java.util.Scanner;

public class SortStability {

    static final int MAX = 100000;

    // Partition function used in Quicksort algorithm
    static int partition(char[] C, int[] A, int p, int r) {
        int i = p - 1;
        char x = C[r];
        int y = A[r];

        for (int j = p; j < r; j++) {
            if (A[j] <= y) {
                i++;
                // Swap A[j] and A[i]
                int tmpN = A[j];
                A[j] = A[i];
                A[i] = tmpN;

                // Swap C[j] and C[i]
                char tmpC = C[j];
                C[j] = C[i];
                C[i] = tmpC;
            }
        }

        // Place the pivot element in its correct position
        int tmpN = A[i + 1];
        A[i + 1] = A[r];
        A[r] = tmpN;

        char tmpC = C[i + 1];
        C[i + 1] = C[r];
        C[r] = tmpC;

        return i + 1;
    }

    // Quicksort function to sort the array recursively
    static void quicksort(char[] C, int[] A, int p, int r) {
        if (p < r) {
            int q = partition(C, A, p, r);
            quicksort(C, A, p, q - 1);
            quicksort(C, A, q + 1, r);
        }
    }

    // Merge function to merge two sorted subarrays
    static void merge(char[] MC, int[] MN, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int[] LN = new int[n1 + 1];
        int[] RN = new int[n2 + 1];
        char[] LC = new char[n1 + 1];
        char[] RC = new char[n2 + 1];

        for (int i = 0; i < n1; i++) {
            LN[i] = MN[left + i];
            LC[i] = MC[left + i];
        }

        for (int i = 0; i < n2; i++) {
            RN[i] = MN[mid + 1 + i];
            RC[i] = MC[mid + 1 + i];
        }

        LN[n1] = Integer.MAX_VALUE; // Sentinel value
        RN[n2] = Integer.MAX_VALUE; // Sentinel value

        int i = 0, j = 0;

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

    // Merge Sort function to sort the array using recursion
    static void mergeSort(char[] MC, int[] MN, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(MC, MN, left, mid);
            mergeSort(MC, MN, mid + 1, right);
            merge(MC, MN, left, mid, right);
        }
    }

    // Main function to read input, sort data using both algorithms, and check stability
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Arrays to store characters and their corresponding numbers
        int[] A = new int[MAX + 1];
        char[] C = new char[MAX + 1];
        char[] MC = new char[MAX + 1];
        int[] MN = new int[MAX + 1];

        // Read the number of elements
        int n = scanner.nextInt();

        // Read characters and their corresponding numbers
        for (int i = 1; i <= n; i++) {
            C[i] = scanner.next().charAt(0);
            A[i] = scanner.nextInt();
        }

        // Copy characters and numbers to another array for Merge Sort
        for (int i = 1; i <= n; i++) {
            MC[i] = C[i];
            MN[i] = A[i];
        }

        // Sort the copied array using Merge Sort
        mergeSort(MC, MN, 1, n);

        // Sort the original array using Quicksort
        quicksort(C, A, 1, n);

        // Check if the sorting results are stable
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (MN[i] == A[i] && MC[i] == C[i]) {
                count++;
            }
        }

        // Print the stability result
        if (count == n) {
            System.out.println("Stable");
        } else {
            System.out.println("Not stable");
        }

        // Print the sorted characters and their corresponding numbers
        for (int i = 1; i <= n; i++) {
            System.out.println(C[i] + " " + A[i]);
        }

        scanner.close();
    }
}

// <END-OF-CODE>
