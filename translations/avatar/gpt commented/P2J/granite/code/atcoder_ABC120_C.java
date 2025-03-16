
import java.io.*;
import java.util.*;

public class atcoder_ABC120_C{
    public static void main(String[] args) throws Exception {
        // Read input string
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        // Check if all characters in the string are the same
        if (s.chars().distinct().count() == 1) {
            System.out.println(0);  // If true, print 0 and exit
            return;
        }

        // Count the occurrences of each character in the string
        Map<Character, Integer> a = new HashMap<>();
        for (char c : s.toCharArray()) {
            a.put(c, a.getOrDefault(c, 0) + 1);
        }

        // Calculate the answer as twice the minimum frequency of any character
        int ans = a.values().stream().mapToInt(Integer::intValue).min().getAsInt() * 2;

        // Print the final answer
        System.out.println(ans);
    }
}

Translate the above Java code to C++ and end with comment "