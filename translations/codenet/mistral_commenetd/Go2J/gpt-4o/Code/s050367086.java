// Import necessary packages
import java.io.*;
import java.util.*;

public class Main {
    // Main function is the entry point of the program
    public static void main(String[] args) throws IOException {
        // Open the standard input and output files
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);

        // Read the first two strings from the input
        String s = reader.readLine();
        String t = reader.readLine();

        // Initialize variables and structures
        int ns = s.length();
        int nt = t.length();
        String[] ss = new String[(nt - 1) / ns + 1];

        // Initialize ss with repeated string s
        Arrays.fill(ss, s);

        // Combine all ss strings into one long string
        String sss = String.join("", ss) + String.join("", ss);

        // Initialize boolean array ok to keep track of unique characters
        boolean[] ok = new boolean[ns];

        // Initialize unordered map mp and array uni for suffix array calculation
        MP mp = new MP();
        mp.init(t);
        int m = 0;

        // Initialize uni array with indices from 0 to n-1
        int[] uni = new int[ns];
        for (int i = 0; i < ns; i++) {
            uni[i] = i;
        }

        // Initialize variable o for checking if current and next characters match
        boolean o;

        // Iterate through all characters in string s
        for (int i = 0; i < ns; i++) {
            // Initialize o to true
            o = true;

            // Iterate through all characters in string t
            while (m < nt) {
                // Check if current character in s matches the character at the same position in t
                if (t.charAt(m) != sss.charAt(i + m)) {
                    // If not, set o to false and break the loop
                    o = false;
                    break;
                }
                // Increment m
                m++;
            }

            // If all characters match, set ok[i] to true and update variables r and m accordingly
            if (o) {
                i += nt - mp.table[m];
                m = mp.table[m];
            }

            // While characters in s and t do not match, update i and m accordingly
            while (m >= 0 && t.charAt(m) != sss.charAt(i + m)) {
                i += m - mp.table[m];
                m = mp.table[m];
            }

            // Decrement i and increment m to move to the next pair of characters
            i--;
            m++;
        }

        // Initialize variable ans to store the answer
        int ans = 0;

        // Initialize variables r and rr for root calculation
        int r, rr;

        // Iterate through all characters in string s again
        for (int i = 0; i < ns; i++) {
            // If ok[i] is false, continue to the next iteration
            if (!ok[i]) {
                continue;
            }

            // If ok[(i + nt) % ns] is false, continue to the next iteration
            if (!ok[(i + nt) % ns]) {
                continue;
            }

            // Calculate roots r and rr of indices i and (i + nt) % ns respectively
            r = root(i, uni);
            rr = root((i + nt) % ns, uni);

            // If roots r and rr are equal, print -1 and exit the program
            if (rr == r) {
                writer.println(-1);
                writer.flush();
                return;
            }

            // Update uni array with root r
            uni[rr] = r;
        }

        // Initialize counter array to store the frequency of each root
        int[] counter = new int[ns];

        // Iterate through all roots and update their frequencies in counter array
        for (int i = 0; i < ns; i++) {
            r = root(i, uni);
            if (!ok[r]) {
                continue;
            }
            counter[r]++;
        }

        // Find the maximum frequency in counter array and store it in variable ans
        for (int i = 0; i < ns; i++) {
            if (ans < counter[i]) {
                ans = counter[i];
            }
        }

        // Print the answer
        writer.println(ans);

        // Flush the writer buffer
        writer.flush();
    }

    // root function returns the root of the given index in uni array
    static int root(int i, int[] uni) {
        // If index i is equal to its root, return i
        if (i == uni[i]) {
            return i;
        }

        // Recursively call root function with the root of index i
        uni[i] = root(uni[i], uni);
        return uni[i];
    }

    // MP class represents a suffix array data structure
    static class MP {
        String s; // Input string
        int[] table; // Suffix array

        // init initializes the MP structure with the given string s
        void init(String s) {
            this.s = s;
            int n = s.length();
            table = new int[n + 1];
            table[0] = -1; // Set first index to -1 for initialization
            int j = -1;
            for (int i = 0; i < n; i++) {
                // While j is not equal to the root of the previous character, update j
                while (j >= 0 && s.charAt(i) != s.charAt(j)) {
                    j = table[j];
                }
                j++;
                // Set table[i] to the index of the next occurrence of the current character in s
                table[i + 1] = j;
            }
        }
    }
}
// <END-OF-CODE>
