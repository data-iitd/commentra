import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the input values for N, d, and x
        int N = scanner.nextInt();
        double d = scanner.nextDouble();
        double x = scanner.nextDouble();
        
        // Call the main function with the input values and print the result
        System.out.println(main(N, d, x));
        
        scanner.close();
    }
    
    public static double main(int N, double d, double x) {
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
