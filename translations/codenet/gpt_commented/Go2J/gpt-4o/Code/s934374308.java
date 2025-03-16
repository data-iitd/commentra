import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables for input values
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int R = scanner.nextInt();
        int S = scanner.nextInt();
        int P = scanner.nextInt();
        String T = scanner.next();

        // Initialize a dictionary to count occurrences of each move
        HashMap<String, Integer> dict = new HashMap<>();
        dict.put("r", 0);
        dict.put("s", 0);
        dict.put("p", 0);
        
        // Create arrays to track the state of each move within the last K moves
        boolean[] s = new boolean[N]; // For 's'
        boolean[] r = new boolean[N]; // For 'r'
        boolean[] p = new boolean[N]; // For 'p'
        
        // Initialize all moves as available (true)
        for (int i = 0; i < N; i++) {
            s[i] = true;
            r[i] = true;
            p[i] = true;
        }
        
        // Iterate through each character in the input string T
        for (int i = 0; i < T.length(); i++) {
            String charMove = T.substring(i, i + 1); // Get the current character

            // Check if we are within the bounds of K
            if (i >= K) {
                // If the current character is the same as the character K positions back
                if (charMove.equals(T.substring(i - K, i + 1 - K))) {
                    // Toggle the availability of the move based on the current character
                    switch (charMove) {
                        case "s":
                            if (s[i % K]) {
                                s[i % K] = false; // Mark 's' as used
                                continue;
                            } else {
                                s[i % K] = true; // Mark 's' as available again
                            }
                            break;

                        case "r":
                            if (r[i % K]) {
                                r[i % K] = false; // Mark 'r' as used
                                continue;
                            } else {
                                r[i % K] = true; // Mark 'r' as available again
                            }
                            break;

                        case "p":
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
                    switch (charMove) {
                        case "s":
                            s[i % K] = true; // Mark 's' as available
                            break;
                        case "r":
                            r[i % K] = true; // Mark 'r' as available
                            break;
                        case "p":
                            p[i % K] = true; // Mark 'p' as available
                            break;
                    }
                }
            }

            // Count the occurrences of each move
            switch (charMove) {
                case "s":
                    dict.put("s", dict.get("s") + 1); // Increment count for 's'
                    break;
                case "r":
                    dict.put("r", dict.get("r") + 1); // Increment count for 'r'
                    break;
                case "p":
                    dict.put("p", dict.get("p") + 1); // Increment count for 'p'
                    break;
            }
        }

        // Calculate the total score based on the counts and respective points
        int res = P * dict.get("r") + S * dict.get("p") + R * dict.get("s");
        
        // Print the final result
        System.out.println(res);
    }
}

// <END-OF-CODE>
