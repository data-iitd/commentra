import java.util.*;
import java.io.*;

public class Main {
    // Define constants for infinity and modulo
    static final long INF = Long.MAX_VALUE;
    static final int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // Read the number of strings to process
        int N = Integer.parseInt(br.readLine().trim());

        // Read N strings from input
        String[] S = new String[N];
        for (int i = 0; i < N; i++) {
            S[i] = br.readLine().trim();
        }

        // Define the target characters to count
        char[] march = {'M', 'A', 'R', 'C', 'H'};
        int[] marchCount = new int[5];

        // Count the occurrences of each character in the input strings
        for (String s : S) {
            char firstChar = Character.toUpperCase(s.charAt(0));
            for (int j = 0; j < march.length; j++) {
                if (firstChar == march[j]) {
                    marchCount[j]++;
                    break;
                }
            }
        }

        // Initialize the answer variable to store the result
        long ans = 0;

        // Calculate the number of ways to choose 3 different characters from the counts
        for (int i = 0; i < marchCount.length; i++) {
            for (int j = i + 1; j < marchCount.length; j++) {
                for (int k = j + 1; k < marchCount.length; k++) {
                    ans += (long) marchCount[i] * marchCount[j] * marchCount[k];
                }
            }
        }

        // Print the final answer
        System.out.println(ans);
    }
}
// <END-OF-CODE>
