import java.util.*; 

public class Main {
    // Initialize scanner for input
    Scanner sc = new Scanner(System.in); 
    
    // Constants for modulo and limits
    final int MOD = 1000000007; 
    final int MAX = Integer.MAX_VALUE; 
    final long LMAX = Long.MAX_VALUE; 
    
    // Length for the array
    int len = (int) 1e6 + 1; 
    
    void doIt() {
        // Read the number of elements N and the long value K
        int N = sc.nextInt(); 
        long K = sc.nextLong(); 
        
        // Initialize the array A to store the input values
        int A[] = new int[N]; 
        
        // Read N integers into the array A and adjust values to be zero-indexed
        for (int i = 0; i < N; i++) { 
            A[i] = sc.nextInt() - 1; 
        } 
        
        // Set to track used indices and arrays to store index and position
        Set<Integer> used = new HashSet<>(); 
        int idx[] = new int[N]; 
        int pos[] = new int[N]; 
        
        // Initialize variables for the cycle detection
        int next = 0, cur = 0; 
        
        // Detect the cycle in the array using the 'used' set
        while (!used.contains(next)) { 
            used.add(next); 
            idx[next] = cur; 
            pos[cur] = next; 
            next = A[next]; 
            cur++; 
        } 
        
        // Calculate the lengths of the cycle and the position of the next element
        long a = (long) cur - idx[next]; 
        long b = (long) idx[next]; 
        
        // Calculate the answer based on the cycle length and K
        int ans = (int) ((10000 * a + K - b) % a + b); 
        
        // If b is greater than K, set ans to K
        if (b > K) ans = (int) K; 
        
        // Output the result, adjusting for 1-based indexing
        System.out.println(pos[ans] + 1); 
    } 
    
    public static void main(String[] args) { 
        // Create an instance of Main and call the doIt method
        new Main().doIt(); 
    }
}
