import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        // Read the first string of runes (s)
        char[] s = br.readLine().toCharArray();
        // Read the second string of runes (t)
        char[] t = br.readLine().toCharArray();

        // Initialize a list to hold possible answers
        List<String> ans = new ArrayList<>();

        // Iterate through the first string to find occurrences of the second string
        for (int i = 0; i < s.length - t.length + 1; i++) {
            boolean f = true; // Flag to check if the current position is valid
            char[] ss = s.clone(); // Create a copy of the original string

            // Check if the substring of s can match t
            for (int j = 0; j < t.length; j++) {
                // If characters do not match and are not '?', set flag to false
                if (s[i + j] != t[j] && s[i + j] != '?') {
                    f = false;
                    break;
                } else {
                    // Replace '?' with the corresponding character from t
                    ss[i + j] = t[j];
                }
            }
            // If the substring matched, replace remaining '?' with 'a' and add the result to the list
            if (f) {
                ans.add(new String(ss).replace('?', 'a'));
            }
        }

        // Sort the possible answers
        Collections.sort(ans);

        // Output the result: either the first valid answer or "UNRESTORABLE"
        if (ans.isEmpty()) {
            bw.write("UNRESTORABLE\n");
        } else {
            bw.write(ans.get(0) + "\n");
        }

        // Flush the buffered writer
        bw.flush();
    }
}
