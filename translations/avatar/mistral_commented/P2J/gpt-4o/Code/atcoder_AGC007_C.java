import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    // Function to read input from standard input
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        
        // Reading input as three integers: N, d, and x
        String[] input = reader.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        double d = Double.parseDouble(input[1]);
        double x = Double.parseDouble(input[2]);
        
        // Calling the main function and printing the result
        System.out.println(calculate(N, d, x));
    }

    // Function definition: calculate takes three arguments N, d, and x
    public static double calculate(int N, double d, double x) {
        // Initializing the result variable to 0
        double ret = 0;

        // Loop continues as long as N is greater than 0
        while (N > 0) {
            // Adding the current term to the result
            ret += d + (N - 0.5) * x;

            // Updating the value of d for the next iteration
            d += d / N + (5 * x) / (2 * N);

            // Updating the value of x for the next iteration
            x += 2 * x / N;

            // Decrementing the value of N for the next iteration
            N--;
        }

        // Returning the final result
        return ret;
    }
}

// <END-OF-CODE>
