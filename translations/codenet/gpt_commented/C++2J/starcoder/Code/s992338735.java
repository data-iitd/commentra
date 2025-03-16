import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Continuously read input until a non-positive integer is entered
        while (sc.hasNextInt() && sc.nextInt() > 0) {
            int N = sc.nextInt();
            int M, m, addup, i;
            
            // Initialize M to a very low value and m to a very high value
            M = -1; // Maximum value initialized to -1 (less than any possible input)
            m = 1001; // Minimum value initialized to 1001 (greater than any possible input)
            addup = 0; // Variable to accumulate the sum of inputs
            
            // Loop to read N integers
            for (i = 0; i < N; i++) {
                int S = sc.nextInt(); // Read the next integer
                
                addup += S; // Add the current integer to the total sum
                
                // Update the maximum value if the current integer is greater
                if (S > M) M = S;
                
                // Update the minimum value if the current integer is smaller
                if (S < m) m = S;
            }
            
            // Calculate the average excluding the maximum and minimum values
            // and print the result
            System.out.println((addup - M - m) / (N - 2));
        }
    }
}
