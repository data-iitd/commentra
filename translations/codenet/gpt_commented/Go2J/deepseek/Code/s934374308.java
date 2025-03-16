import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values: N (length of string), K (window size), R, S, P (points for each move)
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int R = scanner.nextInt();
        int S = scanner.nextInt();
        int P = scanner.nextInt();
        String T = scanner.next();
        
        // Initialize a dictionary to count occurrences of each move
        int[] dict = new int[3]; // r, s, p
        char[] moves = new char[N];
        
        // Create arrays to track the state of each move within the last K moves
        boolean[] s = new boolean[K]; // For 's'
        boolean[] r = new boolean[K]; // For 'r'
        boolean[] p = new boolean[K]; // For 'p'
        
        // Initialize all moves as available (true)
        for (int i = 0; i < K; i++) {
            s[i] = true;
            r[i] = true;
            p[i] = true;
        }
        
        // Iterate through each character in the input string T
        for (int i = 0; i < N; i++) {
            char c = T.charAt(i);
            
            // Check if we are within the bounds of K
            if (i >= K) {
                // If the current character is the same as the character K positions back
                if (c == T.charAt(i - K)) {
                    // Toggle the availability of the move based on the current character
                    switch (c) {
                        case 's':
                            if (s[i % K]) {
                                s[i % K] = false; // Mark 's' as used
                                continue;
                            } else {
                                s[i % K] = true; // Mark 's' as available again
                            }
                            break;
                        case 'r':
                            if (r[i % K]) {
                                r[i % K] = false; // Mark 'r' as used
                                continue;
                            } else {
                                r[i % K] = true; // Mark 'r' as available again
                            }
                            break;
                        case 'p':
                            if (p[i % K]) {
                                p[i % K] = false; // Mark 'p' as used
                                continue;
                            } else {
                                p[i % K] = true; // Mark 'p' as available again
                            }
                            break;
                    }
                } else {
                    // If the current character is different from the character K positions back
                    switch (c) {
                        case 's':
                            s[i % K] = true; // Mark 's' as available
                            break;
                        case 'r':
                            r[i % K] = true; // Mark 'r' as available
                            break;
                        case 'p':
                            p[i % K] = true; // Mark 'p' as available
                            break;
                    }
                }
            }
            
            // Count the occurrences of each move
            switch (c) {
                case 's':
                    dict[0]++; // Increment count for 's'
                    break;
                case 'r':
                    dict[1]++; // Increment count for 'r'
                    break;
                case 'p':
                    dict[2]++; // Increment count for 'p'
                    break;
            }
        }
        
        // Calculate the total score based on the counts and respective points
        int res = P * dict[1] + S * dict[2] + R * dict[0];
        
        // Print the final result
        System.out.println(res);
    }
}
