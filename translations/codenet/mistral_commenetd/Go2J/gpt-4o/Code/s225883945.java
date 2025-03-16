import java.util.Scanner;

public class Main {
    // Initialize scanner for reading input from stdin
    private static final Scanner sc = new Scanner(System.in);

    // Function to read a single word from the input
    private static String next() {
        return sc.next();
    }

    // Function to read an integer from the input
    private static int nextInt() {
        return sc.nextInt();
    }

    // Function to read n integers from the input
    private static int[] nextInts(int n) {
        int[] slice = new int[n];
        // Read n integers and store them in the array
        for (int i = 0; i < n; i++) {
            slice[i] = nextInt();
        }
        return slice;
    }

    // Main function
    public static void main(String[] args) {
        // Read number of elements n and the sum of elements k from the input
        int n = nextInt();
        int k = nextInt();

        // Initialize sum and answer variables
        int sum = 0;
        int ans = 1;

        // Use a loop to find the number of times k can be subtracted from n to reach a non-negative value
        while (sum < n) {
            // Subtract 1 from sum and add k to find the next index to check
            sum = sum - 1 + k;
            // Increment the answer variable for each iteration
            ans++;
        }

        // Print the answer
        System.out.println(ans);
    }
}
// <END-OF-CODE>
