
import java.util.*;

public class Main {

    // The entry point of the program
    public static void main(String[] args) {
        new Main().solve();
    }

    // Initialize a Scanner object to read input from the standard input stream
    private final Scanner sc = new Scanner(System.in);

    // The method to solve the problem
    void solve() {
        // Read the number of test cases
        int N = sc.nextInt();

        // Initialize the maximum and minimum numbers with the first input
        int max = min = sc.nextInt();

        // Read and process the remaining inputs
        for (int i = 1; i < N; i++) {
            int in = sc.nextInt();

            // Update the maximum and minimum numbers with the current input
            max = Math.max(max, in);
            min = Math.min(min, in);
        }

        // Print the result
        System.out.println(max - min);
    }
}