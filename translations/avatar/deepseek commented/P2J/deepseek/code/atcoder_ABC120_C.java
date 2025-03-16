import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        
        // Check if all characters in the string are the same
        if (s.length() == 1) {
            System.out.println(0);
            return;
        }
        
        // Count the frequency of each character in the string
        Map<Character, Integer> a = new HashMap<>();
        for (char c : s.toCharArray()) {
            a.put(c, a.getOrDefault(c, 0) + 1);
        }
        
        // Calculate the answer as twice the minimum frequency of any character
        int minFreq = Collections.min(a.values());
        int ans = minFreq * 2;
        
        // Print the answer
        System.out.println(ans);
    }
}
