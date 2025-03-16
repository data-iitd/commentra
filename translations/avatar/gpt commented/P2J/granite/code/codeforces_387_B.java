
import java.util.Scanner;

public class codeforces_387_B{
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of rounds (n) and the number of George's complexities (m)
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Read the complexities for each round into an array
        int[] roundComplexity = new int[n];
        for (int i = 0; i < n; i++) {
            roundComplexity[i] = scanner.nextInt();
        }
        
        // Read George's complexities into another array
        int[] georgeComplexity = new int[m];
        for (int i = 0; i < m; i++) {
            georgeComplexity[i] = scanner.nextInt();
        }
        
        // Initialize indices for both arrays
        int i = 0, j = 0;
        
        // Iterate through both arrays to compare complexities
        while (i < n && j < m) {
            // If the current round's complexity is less than or equal to George's complexity,
            // move to the next round
            i += (roundComplexity[i] <= georgeComplexity[j])? 1 : 0;
            
            // Always move to the next complexity of George
            j += 1;
        }
        
        // Output the number of rounds that George cannot handle
        System.out.println(n - i);
    }
}

// Entry point of the program
