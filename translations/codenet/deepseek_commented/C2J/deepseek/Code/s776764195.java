public class CountingSort {
    static final int MAX_N = 2000001;
    static final int MAX_Ai = 10001;
    static final int STR_SIZE = 10000010;

    static int[] A = new int[MAX_N]; // Input array
    static int[] B = new int[MAX_N]; // Output array
    static char[] str = new char[STR_SIZE]; // Buffer to read input
    static int p = 0; // Pointer to traverse the buffer

    public static void main(String[] args) throws Exception {
        java.io.BufferedReader reader = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
        reader.read(str); // Read input into the buffer

        int n = getNum(reader); // Get the number of elements
        for (int i = 1; i <= n; ++i) {
            A[i] = getNum(reader); // Read each element into the array A
        }

        CountingSort(A, B, MAX_Ai, n); // Sort the array A using Counting Sort

        p = 0; // Reset the pointer to the start of the buffer
        --n; // Decrement n to exclude the last element from the output
        for (int i = 1; i <= n; ++i) {
            putNum(B[i]); // Write each sorted element
            str[p++] = ' '; // Write a space between elements
        }
        putNum(B[n + 1]); // Write the last element without a space
        str[p++] = '\0'; // Null-terminate the string

        System.out.println(new String(str).trim()); // Output the sorted string
    }

    static int getNum(java.io.BufferedReader reader) throws Exception {
        int n = 0;
        while (str[p] >= '0' && str[p] <= '9') {
            n = n * 10 + (int) (str[p] - '0'); // Convert character to integer
            ++p;
        }
        ++p; // Move past the space or newline
        return n;
    }

    static void putNum(int n) {
        if (n < 10) {
            str[p++] = (char) ('0' + n); // Write single digit number
            return;
        }
        int d = n / 10;
        if (d != 0) putNum(d); // Recursively write higher digits
        str[p++] = (char) ('0' + (n - (d * 10))); // Write the last digit
    }

    static void CountingSort(int[] A, int[] B, int k, int len) {
        int[] C = new int[MAX_Ai]; // Initialize count array
        for (int j = 1; j <= len; ++j) {
            ++C[A[j]]; // Count occurrences of each element
        }
        for (int i = 1; i <= k; ++i) {
            C[i] += C[i - 1]; // Calculate cumulative count
        }
        for (int j = len; j > 0; --j) {
            B[C[A[j]]] = A[j]; // Place elements in sorted order
            --C[A[j]]; // Decrement count for the element
        }
    }
}
