public class Main {
    public static void main(String[] args) {
        // Declare variables for the number of elements (N) and a threshold (T)
        int N, T;
        
        // Read the number of elements and the threshold from input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        N = scanner.nextInt();
        T = scanner.nextInt();
        
        // Initialize an array A to hold the input values
        int[] A = new int[N];
        
        // Initialize a vector B to hold the transformed values
        int[] B = new int[N];
        
        // Read N integers into the array A
        for(int i = 0; i < N; i++) 
            A[i] = scanner.nextInt();
        
        // Initialize m with the first element of A
        int m = A[0];
        
        // Calculate the first element of B based on the first element of A and update m
        B[1] = A[1] - m;
        m = Math.min(m, A[1]);
        
        // Loop through the remaining elements of A to fill B and update m
        for(int i = 2; i < N; i++){
            // Fill B[i] with the difference between A[i] and the minimum value found so far (m)
            B[i] = A[i] - m;
            
            // Update m to be the minimum of the current m and A[i]
            m = Math.min(m, A[i]);
        }
        
        // Count and output the number of times the maximum element in B appears
        int maxElement = java.util.Arrays.stream(B).max().getAsInt();
        int count = 0;
        for (int value : B) {
            if (value == maxElement) {
                count++;
            }
        }
        System.out.println(count);
    }
}
