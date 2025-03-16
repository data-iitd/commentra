
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter wr = new PrintWriter(System.out);

        String s = sc.next(); // Reads the first string.
        String t = sc.next(); // Reads the second string.

        List<String> ans = new ArrayList<>(); // Slice to store possible valid strings.
        for (int i = 0; i < s.length() - t.length() + 1; i++) {
            boolean f = true; // Flag to check if the current position is valid.
            char[] ss = s.toCharArray(); // Temporary array to hold the modified string.
            System.arraycopy(s.toCharArray(), 0, ss, 0, s.length()); // Copies the original string to the temporary array.

            for (int j = 0; j < t.length(); j++) {
                if (s.charAt(i + j) != t.charAt(j) && s.charAt(i + j) != '?') { // Checks if there's a mismatch.
                    f = false;
                    break;
                } else {
                    ss[i + j] = t.charAt(j); // Replaces the character in the temporary array.
                }
            }
            if (f) {
                ans.add(new String(ss).replace("?", "a")); // Adds the valid string to the answer list.
            }
        }
        Collections.sort(ans); // Sorts the answer list.
        if (ans.size() == 0) {
            wr.println("UNRESTORABLE"); // Prints "UNRESTORABLE" if no valid string is found.
        } else {
            wr.println(ans.get(0)); // Prints the smallest valid string.
        }

        wr.close(); // Closes the buffered writer.
    }
}

