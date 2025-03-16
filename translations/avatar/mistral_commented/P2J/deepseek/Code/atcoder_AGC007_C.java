public class Main {
    public static void main(String[] args) {
        // Reading input as three integers: N, d, and x
        String[] input = System.in.read().split(" ");
        int N = Integer.parseInt(input[0]);
        int d = Integer.parseInt(input[1]);
        int x = Integer.parseInt(input[2]);

        // Calling the main function and printing the result
        System.out.println(main(N, d, x));
    }

    // Function definition: main function takes three arguments N, d, and x
    public static int main(int N, int d, int x) {
        // Initializing the result variable to 0
        int ret = 0;

        // Loop continues as long as N is greater than 0
        while (N > 0) {
            // Adding the current term to the result
            ret += d + (N - 0.5) * x;

            // Updating the value of d for the next iteration
            d += d / N + (5 * x) / (2 * N);

            // Updating the value of x for the next iteration
            x += 2 * x / N;

            // Decrementing the value of N for the next iteration
            N -= 1;
        }

        // Returning the final result
        return ret;
    }
}
