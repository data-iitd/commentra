import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the input values for N, d, and x, and convert them to integers
        int N = sc.nextInt();
        int d = sc.nextInt();
        int x = sc.nextInt();
        
        // Initialize the result variable to accumulate the final value
        int ret = 0;
        
        // Loop until N becomes zero
        while (N > 0) {
            // Update the result by adding the current d and a calculated value based on N and x
            ret += d + (N - 0.5) * x;
            
            // Update d based on its current value, N, and x
            d += d / N + (5 * x) / (2 * N);
            
            // Update x based on its current value and N
            x += 2 * x / N;
            
            // Decrement N to move to the next iteration
            N--;
        }
        
        // Print the accumulated result
        System.out.println(ret);
    }
}

