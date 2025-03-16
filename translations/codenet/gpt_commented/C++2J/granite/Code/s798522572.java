
import java.util.*;

public class s798522572{
    public static void main(String[] args) {
        // Declare variables for the number of elements (N) and a threshold (T)
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int T = scanner.nextInt();
        
        // Initialize an array A to hold the input values
        int[] A = new int[N];
        
        // Initialize a vector B to hold the transformed values
        List<Integer> B = new ArrayList<>();
        
        // Read N integers into the array A
        for(int i = 0; i < N; i++) 
            A[i] = scanner.nextInt();
        
        // Initialize m with the first element of A
        int m = A[0];
        
        // Calculate the first element of B based on the first element of A and update m
        B.add(A[1] - m);
        m = Math.min(m, A[1]);
        
        // Loop through the remaining elements of A to fill B and update m
        for(int i = 2; i < N; i++){
            // Fill B[i] with the difference between A[i] and the minimum value found so far (m)
            B.add(A[i] - m);
            
            // Update m to be the minimum of the current m and A[i]
            m = Math.min(m, A[i]);
        }
        
        // Count and output the number of times the maximum element in B appears
        int max = Collections.max(B);
        int count = 0;
        for(int i : B) {
            if(i == max) {
                count++;
            }
        }
        System.out.println(count);
    }
}
