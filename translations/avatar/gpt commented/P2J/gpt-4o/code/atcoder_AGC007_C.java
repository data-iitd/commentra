import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        // Set up input reading methods for efficient reading from standard input
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        
        // Read the input values for N, d, and x, and convert them to integers
        String[] input = reader.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        double d = Double.parseDouble(input[1]);
        double x = Double.parseDouble(input[2]);
        
        // Call the main function with the input values and print the result
        System.out.println(calculate(N, d, x));
    }

    public static double calculate(int N, double d, double x) {
        // Initialize the result variable to accumulate the final value
        double ret = 0;

        // Loop until N becomes zero
        while (N > 0) {
            // Update the result by adding the current d and a calculated value based on N and x
            ret += d + (N - 0.5) * x;

            // Update d based on its current value, N, and x
            d = d + (d / N) + (5 * x) / (2 * N);

            // Update x based on its current value and N
            x += 2 * x / N;

            // Decrement N to move to the next iteration
            N--;
        }

        // Return the accumulated result
        return ret;
    }
}

// <END-OF-CODE>
