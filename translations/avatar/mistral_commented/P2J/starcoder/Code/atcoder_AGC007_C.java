
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Reading input as three integers: N, d, and x
        int N = sc.nextInt();
        int d = sc.nextInt();
        int x = sc.nextInt();

        // Function definition: main function takes three arguments N, d, and x
        int ret = 0;
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
        System.out.println(ret);
    }
}

