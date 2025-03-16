
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class s776764195{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        // Read the entire input into the string
        String input = br.readLine();

        // Get the number of elements from the input
        int n = Integer.parseInt(input);
        // Read each number into the array A
        int[] A = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            A[i] = Integer.parseInt(br.readLine());
        }

        // Perform counting sort on the array A and store the result in B
        int[] B = new int[n + 1];
        countingSort(A, B, 10001, n);

        // Reset the pointer to the start of the output string
        pw.print(B[1]);
        for (int i = 2; i <= n; ++i) {
            pw.print(' ');
            pw.print(B[i]);
        }
        pw.println();

        pw.close();
    }

    // Function to read an integer from the input string
    private static int getNum(String input, int[] pos) {
        int n = 0; // Variable to store the number
        // Read digits until a non-digit character is encountered
        int i = pos[0];
        while (i < input.length() && Character.isDigit(input.charAt(i))) {
            n = n * 10 + (int)(input.charAt(i) - '0'); // Build the number
            ++i; // Move to the next character
        }
        pos[0] = i; // Update the position
        return n; // Return the read number
    }

    // Function to write an integer to the output string
    private static void putNum(int n, StringBuilder sb) {
        int d; // Variable for division
        // Handle single-digit numbers directly
        if (n < 10) {
            sb.append((char)(n + '0')); // Convert to character and append
            return;
        }
        // Recursively write the digits of the number
        d = n / 10; // Get the quotient
        if (d > 0) {
            putNum(d, sb); // Recursively call for the quotient
        }
        sb.append((char)(n - (d * 10) + '0')); // Append the last digit
    }

    // Counting sort algorithm implementation
    private static void countingSort(int[] A, int[] B, int k, int len) {
        int[] C = new int[k + 1]; // Count array initialized to zero
        int i, j;
        // Count occurrences of each number in A
        for (j = 1; j <= len; ++j) {
            ++C[A[j]]; // Increment count for each number
        }
        // Update count array to hold the position of each number
        for (i = 1; i <= k; ++i) {
            C[i] += C[i - 1]; // C[i] now contains the position
        }
        // Build the output array B using the count array
        for (j = len; j > 0; --j) {
            B[C[A[j]]] = A[j]; // Place the number in the correct position
            --C[A[j]]; // Decrement the count for the number
        }
    }
}

