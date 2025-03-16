// Package declaration
import java.util.Scanner;

// Class declaration
public class Main {
    // Constants declaration with initializing size of the memory array
    static final int SIZE = 100001;

    // Main function
    public static void main(String[] args) {
        // Variable declaration and initialization for number of queries and time interval
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int t = scanner.nextInt();

        // Initializing memory array with zero values
        int[] mem = new int[SIZE];

        // Iterating through each query in the input
        for (int i = 0; i < n; i++) {
            // Reading input values for start and end time intervals
            int l = scanner.nextInt();
            int r = scanner.nextInt();

            // Updating memory array values for start and end time intervals
            mem[l] += 1;
            mem[r] -= 1;
        }

        // Initializing variable for answer
        int ans = mem[0];

        // Iterating through each time interval in the memory array
        for (int i = 1; i <= t; i++) {
            // Updating memory array values by adding previous value
            mem[i] += mem[i - 1];

            // Updating answer if current memory array value is greater than previous answer
            if (ans < mem[i]) {
                ans = mem[i];
            }
        }

        // Printing the final answer
        System.out.println(ans);
    }
}
// <END-OF-CODE>
