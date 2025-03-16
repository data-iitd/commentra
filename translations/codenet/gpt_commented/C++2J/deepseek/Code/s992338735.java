public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        while (scanner.hasNextInt() && scanner.nextInt() > 0) {
            int N = scanner.nextInt();
            int M = -1; // Maximum value initialized to -1 (less than any possible input)
            int m = 1001; // Minimum value initialized to 1001 (greater than any possible input)
            int addup = 0; // Variable to accumulate the sum of inputs
            
            // Loop to read N integers
            for (int i = 0; i < N; i++) {
                int S = scanner.nextInt(); // Read the next integer
                
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
