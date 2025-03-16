
public class Main {
    public static void main(String[] args) {
        int n; // Variable to store the number of integers to be read
        int[] A = new int[MAX_N]; // Array to store the input integers
        int[] B = new int[MAX_N]; // Array to store the sorted integers
        char[] str = new char[STR_SIZE]; // Buffer to store the input string
        char[] p = str; // Pointer to the current position in the string

        n = getNum(); // Function to read an integer from the input string

        for (int i = 0; i < n; i++) {
            A[i] = getNum(); // Function to read an integer from the input string
        }

        CountingSort(A, B, MAX_Ai, n); // Function to perform counting sort

        for (int i = 0; i < n; i++) {
            putNum(B[i]); // Function to write an integer to the output string
        }
    }

    public static int getNum() {
        int n = 0; // Variable to store the number of integers to be read
        char c; // Variable to store the current character

        while ((c = p[n++]) != '\n') {
            ;
        }

        return n - 1;
    }

    public static void putNum(int n) {
        int i = 0; // Variable to store the current position in the string

        while (n > 0) {
            p[i++] = (char) (n % 10 + '0');
            n /= 10;
        }

        while (i > 0) {
            p[i--] = p[i];
        }

        p[i] = '\n';
    }

    public static void CountingSort(int[] A, int[] B, int k, int len) {
        int[] C = new int[k]; // Array to store the count of each integer

        for (int i = 0; i < len; i++) {
            C[A[i]]++; // Increment the count of the current integer
        }

        for (int i = 1; i < k; i++) {
            C[i] += C[i - 1]; // Compute the cumulative count
        }

        for (int i = len - 1; i >= 0; i--) {
            B[C[A[i]] - 1] = A[i]; // Store the current integer in the correct position
            C[A[i]]--; // Decrement the count of the current integer
        }
    }
}

