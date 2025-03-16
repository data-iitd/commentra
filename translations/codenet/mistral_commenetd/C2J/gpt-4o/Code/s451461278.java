import java.util.Scanner;

public class Main {
    static final int MAX = 100000;

    // Function declarations
    static int partition(char[] C, int[] A, int p, int r) {
        int i, j; // Variables declaration
        char tmpC, x; // Variables declaration
        int tmpN, y; // Variables declaration

        // Set the pivot element as the last element of the array
        x = C[r];
        y = A[r];

        // Set the initial index of the left partition as p - 1
        i = p - 1;

        // Iterate through the array from p to r - 1
        for (j = p; j < r; j++) {
            // If the current element is smaller than the pivot, increment i and swap the elements
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

        // Swap the pivot element with the element at index i + 1
        tmpN = A[i + 1];
        tmpC = C[i + 1];
        A[i + 1] = A[r];
        C[i + 1] = C[r];
        A[r] = tmpN;
        C[r] = tmpC;

        // Return the index of the pivot element
        return i + 1;
    }

    static void quicksort(char[] C, int[] A, int p, int r) {
        // Base case: if p is less than r, recursively call partition and quicksort functions
        if (p < r) {
            int q = partition(C, A, p, r);
            quicksort(C, A, p, q - 1);
            quicksort(C, A, q + 1, r);
        }
    }

    static void merge(char[] MC, int[] MN, int left, int mid, int right) {
        int n1 = mid - left + 1; // Calculate the size of the left partition
        int n2 = right - mid; // Calculate the size of the right partition
        int[] LN = new int[n1 + 1]; // Dynamically allocate memory for the left partition of integers
        int[] RN = new int[n2 + 1]; // Dynamically allocate memory for the right partition of integers
        char[] LC = new char[n1 + 1]; // Dynamically allocate memory for the left partition of characters
        char[] RC = new char[n2 + 1]; // Dynamically allocate memory for the right partition of characters

        // Copy the left partition to LN and LC arrays
        for (int i = 1; i <= n1; i++) {
            LN[i] = MN[left + i - 1];
            LC[i] = MC[left + i - 1];
        }

        // Copy the right partition to RN and RC arrays
        for (int i = 1; i <= n2; i++) {
            RN[i] = MN[mid + i];
            RC[i] = MC[mid + i];
        }

        // Set the sentinel values for LN and RN arrays
        LN[n1] = 1000000000;
        RN[n2] = 1000000000;

        // Merge the left and right partitions into the original arrays
        int i = 1, j = 1, k = left;
        while (i <= n1 && j <= n2) {
            if (LN[i] <= RN[j]) {
                MN[k] = LN[i];
                MC[k] = LC[i];
                i++;
            } else {
                MN[k] = RN[j];
                MC[k] = RC[j];
                j++;
            }
            k++;
        }
    }

    static void mergeSort(char[] MC, int[] MN, int left, int right) {
        int mid; // Variable declaration

        // Base case: if left is less than right, recursively call mergeSort and merge functions
        if (left < right) {
            mid = (left + right) / 2;
            mergeSort(MC, MN, left, mid);
            mergeSort(MC, MN, mid + 1, right);
            merge(MC, MN, left, mid, right);
        }
    }

    // Main function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] A = new int[MAX + 1]; // Dynamically allocated array for integers A
        char[] C = new char[MAX + 1]; // Dynamically allocated array for characters C
        char[] MC = new char[MAX + 1]; // Dynamically allocated array for characters MC (Modified C)
        int[] MN = new int[MAX + 1]; // Dynamically allocated array for integers MN (Modified N)

        int n; // Variable declaration and initialization
        int count = 0;

        n = scanner.nextInt(); // Read the number of elements n

        // Read characters and integers from the standard input
        for (int i = 1; i <= n; i++)
            C[i] = scanner.next().charAt(0); // Read character
            A[i] = scanner.nextInt(); // Read integer

        // Copy characters and integers from A to MC and MN respectively
        for (int i = 1; i <= n; i++) {
            MC[i] = C[i];
            MN[i] = A[i];
        }

        // Merge sort on MC and MN arrays
        mergeSort(MC, MN, 1, n);

        // Quick sort on C and A arrays
        int p = 1;
        quicksort(C, A, p, n);

        // Check if the arrays are equal after sorting
        for (int i = 1; i <= n; i++) {
            if (MN[i] == A[i] && MC[i] == C[i])
                count++;
        }

        // Print the result
        if (count == n)
            System.out.println("Stable");
        else
            System.out.println("Not stable");

        // Print the sorted arrays
        for (int i = 1; i <= n; i++)
            System.out.println(C[i] + " " + A[i]);

        scanner.close();
    }
}
// <END-OF-CODE>
