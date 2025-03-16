public class Sorting {
    static final int MAX = 100000;

    // Partition function used in Quicksort algorithm
    static int Partition(char[] C, int[] A, int p, int r) {
        // Variables to store temporary values during partition
        int i, j;
        char tmpC;
        int tmpN;

        // Choose the last element as pivot
        char x = C[r];
        int y = A[r];
        i = p - 1;

        // Rearrange elements in the array
        for (j = p; j < r; j++) {
            if (A[j] <= y) {
                i = i + 1;
                tmpN = A[j];
                tmpC = C[j];
                A[j] = A[i];
                C[j] = C[i];
                A[i] = tmpN;
                C[i] = tmpC;
            }
        }

        // Place the pivot element in its correct position
        tmpN = A[i + 1];
        tmpC = C[i + 1];
        A[i + 1] = A[r];
        C[i + 1] = C[r];
        A[r] = tmpN;
        C[r] = tmpC;

        return i + 1;
    }

    // Quicksort function to sort the array recursively
    static void Quicksort(char[] C, int[] A, int p, int r) {
        // Base case: if the subarray has more than one element
        if (p < r) {
            int q = Partition(C, A, p, r);
            Quicksort(C, A, p, q - 1);
            Quicksort(C, A, q + 1, r);
        }
    }

    // Merge function to merge two sorted subarrays
    static void Merge(char[] MC, int[] MN, int left, int mid, int right) {
        // Calculate sizes of two subarrays to be merged
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int[] LN = new int[n1 + 1];
        int[] RN = new int[n2 + 1];
        char[] LC = new char[n1 + 1];
        char[] RC = new char[n2 + 1];

        // Copy data to temp arrays
        for (int i = 1; i <= n1; i++) {
            LN[i] = MN[left + i - 1];
            LC[i] = MC[left + i - 1];
        }

        for (int i = 1; i <= n2; i++) {
            RN[i] = MN[mid + i];
            RC[i] = MC[mid + i];
        }

        // Sentinel values to avoid checking if any subarray is empty
        LN[n1 + 1] = Integer.MAX_VALUE;
        RN[n2 + 1] = Integer.MAX_VALUE;

        // Initial indexes for subarrays
        int i = 1;
        int j = 1;

        // Merge the temp arrays back into arr[left..right]
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
    static void Merge_Sort(char[] MC, int[] MN, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            Merge_Sort(MC, MN, left, mid);
            Merge_Sort(MC, MN, mid + 1, right);
            Merge(MC, MN, left, mid, right);
        }
    }

    public static void main(String[] args) {
        // Arrays to store characters and their corresponding numbers
        int[] A = new int[MAX + 1];
        char[] C = new char[MAX + 1];
        char[] MC = new char[MAX + 1];
        int[] MN = new int[MAX + 1];

        // Variables to store the number of elements and loop index
        int i, p, n;

        // Read the number of elements
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();

        // Read characters and their corresponding numbers
        for (i = 1; i <= n; i++) {
            C[i] = scanner.next().charAt(0);
            A[i] = scanner.nextInt();
        }

        // Copy characters and numbers to another array for Merge Sort
        for (i = 1; i <= n; i++) {
            MC[i] = C[i];
            MN[i] = A[i];
        }

        // Sort the copied array using Merge Sort
        Merge_Sort(MC, MN, 1, n);

        // Sort the original array using Quicksort
        p = 1;
        Quicksort(C, A, p, n);

        // Check if the sorting results are stable
        int count = 0;
        for (i = 1; i <= n; i++) {
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
        for (i = 1; i <= n; i++) {
            System.out.println(C[i] + " " + A[i]);
        }
    }
}
