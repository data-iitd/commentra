import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values for n and k
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read the list of integers M from input
        int[] M = new int[n];
        for (int i = 0; i < n; i++) {
            M[i] = scanner.nextInt();
        }
        
        // Initialize a variable m to zero (not used in the current logic)
        int m = 0;
        
        // Outer loop to iterate over each index j in the range of n
        for (int j = 0; j < n; j++) {
            // Inner loop to find the first index p where M[p] is zero
            int p = -1;
            for (int l = 0; l < n; l++) {
                if (M[l] == 0) {
                    p = l;
                    break;
                }
            }
            
            // Print the index (1-based) where M[p] is zero
            System.out.print((p + 1) + " ");
            
            // Decrease the values in M from the start up to p + 1 - k
            for (int l = 0; l < p + 1 - k; l++) {
                M[l]--;
            }
            
            // Decrease the value at index p in M
            if (p != -1) {
                M[p]--;
            }
        }
    }
}
