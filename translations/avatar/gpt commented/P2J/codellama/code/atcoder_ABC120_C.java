
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Set up input reading methods for efficiency
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        // Check if all characters in the string are the same
        if (s.length() == 1) {
            System.out.println(0);  // If true, print 0 and exit
            System.exit(0);
        }

        // Count the occurrences of each character in the string
        Map<Character, Integer> a = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (a.containsKey(c)) {
                a.put(c, a.get(c) + 1);
            } else {
                a.put(c, 1);
            }
        }

        // Calculate the answer as twice the minimum frequency of any character
        int ans = 0;
        for (int v : a.values()) {
            ans = Math.max(ans, v * 2);
        }

        // Print the final answer
        System.out.println(ans);
    }
}

