
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class s050367086{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st;

        // Initialize file pointers for input and output
        // (Commented out as it is not relevant to the translation)

        // Create a scanner for reading input and a writer for output
        // (Commented out as it is not relevant to the translation)

        // Read two strings from input
        String s = br.readLine();
        String t = br.readLine();

        // Calculate lengths of the input strings
        int ns = s.length();
        int nt = t.length();

        // Create a slice to hold repeated instances of string s
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < (nt - 1) / ns + 1; i++) {
            sb.append(s);
        }
        String sss = sb.toString();

        // Initialize a boolean slice to track matches
        boolean[] ok = new boolean[ns];

        // Initialize a unique index array and a pattern matching structure
        int[] uni = new int[ns];
        MP mp = new MP();
        mp.init(t); // Initialize the pattern matching table with string t
        int m = 0;
        for (int i = 0; i < ns; i++) {
            uni[i] = i; // Set each index to itself initially
        }
        boolean o = true;

        // Check for matches of string t in the concatenated string sss
        for (int i = 0; i < ns; i++) {
            o = true;
            for (m = 0; m < nt; ) {
                if (t.charAt(m)!= sss.charAt(i + m)) { // Compare characters
                    o = false;
                    break;
                }
                m++;
            }
            ok[i] = o; // Store the result of the match
            if (o) {
                i += nt - mp.table[m]; // Update index based on the pattern table
                m = mp.table[m]; // Update match index
            }
            for (; m >= 0 && t.charAt(m)!= sss.charAt(i + m); ) {
                i += m - mp.table[m]; // Update index if mismatch occurs
                m = mp.table[m]; // Update match index
            }
            i--; // Adjust index for the next iteration
            m++; // Move to the next character
        }

        // Calculate the answer based on the matches found
        int ans = 0;
        int r, rr;
        for (int i = 0; i < ns; i++) {
            if (!ok[i]) {
                continue; // Skip if no match
            }
            if (!ok[(i + nt) % ns]) {
                continue; // Skip if no match for the next index
            }
            r = root(i, uni); // Find the root of the current index
            rr = root((i + nt) % ns, uni); // Find the root of the next index
            if (rr == r) {
                pw.println(-1); // Output -1 if they are in the same component
                pw.flush();
                return;
            }
            uni[rr] = r; // Union the two components
        }

        // Count the number of matches for each unique root
        int[] counter = new int[ns];
        for (int i = 0; i < ns; i++) {
            r = root(i, uni); // Find the root for the current index
            if (!ok[r]) {
                continue; // Skip if no match
            }
            counter[r]++; // Increment the count for the root
        }
        for (int i = 0; i < ns; i++) {
            if (ans < counter[i]) {
                ans = counter[i]; // Update the answer with the maximum count
            }
        }

        // Output the final answer
        pw.println(ans);

        pw.flush(); // Flush the writer to ensure all output is written
    }

    // root function finds the root of the given index using path compression.
    private static int root(int i, int[] uni) {
        if (i == uni[i]) {
            return i; // Return if the index is its own root
        }

        uni[i] = root(uni[i], uni); // Path compression
        return uni[i]; // Return the root
    }

    // MP struct holds the string and its pattern matching table.
    private static class MP {
        String s;
        int[] table;

        void init(String s) {
            this.s = s;
            int n = s.length();
            table = new int[n + 1];
            table[0] = -1; // Initialize the first value of the table
            int j = -1;
            for (int i = 0; i < n; i++) {
                for (j = j >= 0 && s.charAt(i)!= s.charAt(j)? table[j] : j; j >= 0 && s.charAt(i)!= s.charAt(j); ) {
                    j = table[j]; // Update j based on the table
                }
                j++;
                table[i + 1] = j; // Fill the table with the length of the longest prefix
            }
        }
    }
}

