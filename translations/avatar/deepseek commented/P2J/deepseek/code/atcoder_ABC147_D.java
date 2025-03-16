public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        // Read the size of the array
        int N = scanner.nextInt();
        
        // Read the array elements
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        
        // Initialize the result variable to 0
        long result = 0;
        
        // Loop over each bit position from 0 to 59
        for (int b = 0; b < 60; b++) {
            // Count the number of set bits at the current bit position
            int bs = 0;
            for (int i = 0; i < N; i++) {
                if (((A[i] >> b) & 1) == 1) {
                    bs++;
                }
            }
            
            // Calculate the contribution of the current bit position to the result
            result = (result + bs * (N - bs) * (1L << b)) % 1000000007;
        }
        
        // Print the final result
        System.out.println(result);
    }
}
