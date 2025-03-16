
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a new Scanner object to read input from the standard input
        Scanner in = new Scanner(System.in);

        // Read the first integer `n` representing the number of test cases
        int n = in.nextInt();

        // Allocate three arrays `c`, `s`, and `f` of size `n-1` to store the input data for each test case
        int[] c = new int[n - 1];
        int[] s = new int[n - 1];
        int[] f = new int[n - 1];

        // Use a for loop to read the input data for each test case and store it in the corresponding arrays
        for (int i = 0; i < n - 1; i++) {
            // Read the number of chips `c[i]` for the current test case
            c[i] = in.nextInt();

            // Read the starting time `s[i]` for the current test case
            s[i] = in.nextInt();

            // Read the frequency `f[i]` for the current test case
            f[i] = in.nextInt();
        }

        // Use an inner for loop to calculate the finishing time for each test case based on the given constraints
        for (int i = 0; i < n - 1; i++) {
            int time = s[i] + c[i]; // Initialize the variable `time` with the sum of starting time and number of chips for the current test case

            for (int j = i + 1; j < n - 1; j++) { // Use an inner for loop to check the interference between the current test case and the next one
                if (time % f[j] != 0) { // If the current test case finishes before the next one starts, we need to add the multiple of the frequency of the next test case to make them aligned
                    time += f[j] - (time % f[j]);
                }

                if (time < s[j]) { // If the current test case finishes before the next one starts, we need to update the `time` variable with the starting time of the next test case to calculate the interference correctly
                    time = s[j];
                }

                time += c[j]; // Add the number of chips for the next test case to the current `time` variable
            }

            // Print the finishing time for the current test case
            System.out.println(time);
        }

        // Print `0` as the output for the last test case
        System.out.println(0);

        // Close the Scanner object to release the system resources
        in.close();
    }
}