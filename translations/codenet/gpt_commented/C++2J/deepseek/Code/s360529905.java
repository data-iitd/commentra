public class Main {
    public static void main(String[] args) {
        // Declare variables for the arrays and loop index and size
        int[] a, b;
        int i, N;
        int frontHalf, backHalf;

        // Read the number of elements
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        N = scanner.nextInt();

        // Dynamically allocate memory for two arrays of size N
        a = new int[N];
        b = new int[N];

        // Read elements into array 'a' and copy them to array 'b'
        for(i = 0; i < N; i++) {
            a[i] = scanner.nextInt(); // Read element into array 'a'
            b[i] = a[i];              // Copy element from 'a' to 'b'
        }

        // Sort the array 'b' to find the median values
        java.util.Arrays.sort(b);

        // Determine the two middle values (for even-sized arrays)
        frontHalf = b[N / 2 - 1]; // Value just before the median
        backHalf = b[N / 2];      // Median value

        // Output the appropriate value based on the original array 'a'
        for(i = 0; i < N; i++) {
            // If the current element is less than the backHalf (median), print backHalf
            if(a[i] < backHalf)
                System.out.println(backHalf);
            // Otherwise, print frontHalf
            else
                System.out.println(frontHalf);
        }

        // Free the memory allocated for array 'b'
        b = null;

        // Free the memory allocated for array 'a'
        a = null;
    }
}
