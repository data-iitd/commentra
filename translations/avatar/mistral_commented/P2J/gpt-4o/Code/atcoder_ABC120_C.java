import java.util.*;
import java.io.*;

public class Main {
    // Define constants
    static final long INF = Long.MAX_VALUE;
    static final int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        // Set up input reading
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // Read input string
        String s = br.readLine();
        
        // Check if all characters in the string are the same
        if (new HashSet<>(Arrays.asList(s.split(""))).size() == 1) {
            // If so, print 0 and exit
            System.out.println(0);
            return;
        }

        // Count the occurrences of each character in the string
        Map<Character, Integer> countMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            countMap.put(c, countMap.getOrDefault(c, 0) + 1);
        }

        // Calculate the answer
        int ans = Collections.min(countMap.values()) * 2;

        // Print the answer
        System.out.println(ans);
    }
}

// <END-OF-CODE>
