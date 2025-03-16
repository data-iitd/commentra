public class CountingSort {
    // Define constants for maximum sizes
    static final int MAX_N = 2000001; // Maximum number of elements
    static final int MAX_Ai = 10001; // Maximum value of elements
    static final int STR_SIZE = 10000010; // Size of the output string

    // Global arrays for input and output
    static int[] A = new int[MAX_N]; // Array to hold input numbers
    static int[] B = new int[MAX_N]; // Array to hold sorted numbers
    static char[] str = new char[STR_SIZE]; // Buffer for output string
    static char[] p = new char[STR_SIZE]; // Pointer to the current position in the output string

    public static void main(String[] args) {
        int n; // Number of elements to sort

        // Read the entire input into the string
        System.in.read(str);

        // Get the number of elements from the input
        n = getNum();
        // Read each number into the array A
        for (int i = 1; i <= n; ++i) {
            A[i] = getNum();
        }

        // Perform counting sort on the array A and store the result in B
        CountingSort(A, B, MAX_Ai, n);

        // Reset the pointer to the start of the output string
        p = str;
        --n; // Adjust n for zero-based indexing
        // Write the sorted numbers to the output string
        for (int i = 1; i <= n; ++i) {
            putNum(B[i]); // Convert number to string and append
            p[0] = ' '; // Append a space after each number
        }
        putNum(B[i]); // Append the last number without a trailing space
        p[0] = '\0'; // Null-terminate the output string

        // Output the final result
        System.out.println(new String(str));
    }

    // Function to read an integer from the input string
    static int getNum() {
        int n = 0; // Variable to store the number
        // Read digits until a non-digit character is encountered
        while ((p[0] >= '0') && (p[0] <= '9')) {
            n = n * 10 + (int)(p[0] - '0'); // Build the number
            ++p; // Move to the next character
        }
        ++p; // Skip the non-digit character (likely a space or newline)
        return n; // Return the read number
    }

    // Function to write an integer to the output string
    static void putNum(int n) {
        int d; // Variable for division
        // Handle single-digit numbers directly
        if (n < 10) {
            p[0] = (char)('0' + n); // Convert to character and append
            p++; // Move to the next position
            return;
        }
        // Recursively write the digits of the number
        d = n / 10; // Get the quotient
        if (d > 0) putNum(d); // Recursively call for the quotient
        p[0] = (char)('0' + (n - (d * 10))); // Append the last digit
        p++; // Move to the next position
    }

    // Counting sort algorithm implementation
    static void CountingSort(int A[], int B[], int k, int len) {
        int[] C = new int[MAX_Ai]; // Count array initialized to zero
        // Count occurrences of each number in A
        for (int j = 1; j <= len; ++j) {
            ++C[A[j]]; // Increment count for each number
        }
        // Update count array to hold the position of each number
        for (int i = 1; i <= k; ++i) {
            C[i] += C[i - 1]; // C[i] now contains the position
        }
        // Build the output array B using the count array
        for (int j = len; j > 0; --j) {
            B[C[A[j]]] = A[j]; // Place the number in the correct position
            --C[A[j]]; // Decrement the count for the number
        }
    }
}
