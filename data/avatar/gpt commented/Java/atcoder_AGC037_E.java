import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        try {
            // Read the integer N (length of the string) and K (number of operations)
            final int N = sc.nextInt();
            int K = sc.nextInt();
            
            // Read the initial string and create a StringBuilder for manipulation
            StringBuilder S = new StringBuilder(sc.next());
            
            // Flag to check if we are processing the first iteration
            boolean firstTime = true;
            // Variable to control the step size for substring extraction
            int step = 1;
            
            // Loop until K operations are performed
            while (K > 0) {
                // Create a reversed copy of the current string S
                StringBuilder T = new StringBuilder(S.toString());
                T.reverse();
                
                // Create a new StringBuilder that combines S and its reverse, then reverse it
                StringBuilder revU = new StringBuilder(S.toString() + T.toString());
                revU.reverse();
                
                // Initialize a variable to keep track of the best string found so far
                String sDash = S.toString();
                
                // Iterate through the string revU to find the lexicographically smallest substring
                for (int i = N; i >= 0; i -= step) {
                    // Extract a substring from revU
                    String tmp = revU.substring(i, i + N);
                    
                    // Compare and update sDash if a smaller substring is found
                    if (sDash.compareTo(tmp) > 0) {
                        sDash = tmp;
                    } else {
                        // If we are not in the first iteration, break the loop
                        if (!firstTime) {
                            break;
                        }
                    }
                }
                
                // If this is the first iteration, check if we can print a uniform string
                if (firstTime) {
                    firstTime = false;
                    // If 2^K is greater than N, print the first character of sDash N times
                    if (Math.pow(2, K) > N) {
                        char c = sDash.charAt(0);
                        for (int i = 0; i < N; i++) {
                            System.out.print(c);
                        }
                        System.out.println();
                        System.exit(0);
                    }
                } else {
                    // Increase the step size for the next iteration
                    step += step;
                }
                
                // Decrement K and update S for the next operation
                K--;
                S = new StringBuilder(sDash);
                S.reverse();
            }
            
            // Print the final result after all operations
            System.out.println(S.reverse());
        } finally {
            // Close the scanner to free up resources
            sc.close();
        }
    }
}
