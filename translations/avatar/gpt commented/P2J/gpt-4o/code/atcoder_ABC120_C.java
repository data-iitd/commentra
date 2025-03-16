import java.util.*;
import java.io.*;

public class Main {
    // Define constants for infinity and modulo operations
    static final long INF = Long.MAX_VALUE;
    static final int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        // Set up input reading methods for efficiency
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // Read input string
        String s = br.readLine();

        // Check if all characters in the string are the same
        if (new HashSet<>(Arrays.asList(s.split(""))).size() == 1) {
            System.out.println(0);  // If true, print 0 and exit
            return;
        }

        // Count the occurrences of each character in the string
        Map<Character, Integer> countMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            countMap.put(c, countMap.getOrDefault(c, 0) + 1);
        }

        // Calculate the answer as twice the minimum frequency of any character
        int minCount = Collections.min(countMap.values());
        int ans = minCount * 2;

        // Print the final answer
        System.out.println(ans);
    }
}

// <END-OF-CODE>
