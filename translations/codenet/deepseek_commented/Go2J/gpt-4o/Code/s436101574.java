import java.util.*;
import java.io.*;

public class Main {
    // Buffered reader and writer for input and output
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    // Reads a single string from the input.
    static String scanString() throws IOException {
        return br.readLine();
    }

    // Main function where the program execution begins.
    public static void main(String[] args) throws IOException {
        String s = scanString(); // Reads the first string.
        String t = scanString(); // Reads the second string.

        List<String> ans = new ArrayList<>(); // List to store possible valid strings.
        for (int i = 0; i <= s.length() - t.length(); i++) {
            boolean f = true; // Flag to check if the current position is valid.
            char[] ss = s.toCharArray(); // Temporary array to hold the modified string.

            for (int j = 0; j < t.length(); j++) {
                if (s.charAt(i + j) != t.charAt(j) && s.charAt(i + j) != '?') { // Checks if there's a mismatch.
                    f = false;
                    break;
                } else {
                    ss[i + j] = t.charAt(j); // Replaces the character in the temporary array.
                }
            }
            if (f) {
                // Replace '?' with 'a' in the modified string and add to the answer list.
                String modifiedString = new String(ss).replace('?', 'a');
                ans.add(modifiedString);
            }
        }
        Collections.sort(ans); // Sorts the answer list.
        if (ans.isEmpty()) {
            pw.println("UNRESTORABLE"); // Prints "UNRESTORABLE" if no valid string is found.
        } else {
            pw.println(ans.get(0)); // Prints the smallest valid string.
        }
        pw.flush(); // Ensures the buffered writer is flushed after the function completes.
    }
}
// <END-OF-CODE>
