
package main

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {
        // Initialize file pointers for input and output
        BufferedReader fp = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader wfp = new BufferedReader(new InputStreamReader(System.out));

        // Check for environment variables to override input and output file pointers
        if (System.getenv("MASPY") != null) {
            fp = new BufferedReader(new InputStreamReader(System.in)); // Open specified input file
        }
        if (System.getenv("MASPYPY") != null) {
            wfp = new BufferedReader(new InputStreamReader(System.out)); // Create specified output file
        }

        // Create a scanner for reading input and a writer for output
        Scanner scanner = new Scanner(fp);
        Writer writer = new Writer(wfp);

        // Read two strings from input
        String s = scanner.getNextString();
        String t = scanner.getNextString();

        // Calculate lengths of the input strings
        int ns = s.length();
        int nt = t.length();

        // Create a slice to hold repeated instances of string s
        List<String> ss = new ArrayList<String>();
        for (int i = 0; i < (nt - 1) / ns + 1; i++) {
            ss.add(s); // Fill the slice with string s
        }

        // Concatenate the repeated strings to form a new string
        String sss = String.join("", ss) + String.join("", ss);

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
        boolean o = false;

        // Check for matches of string t in the concatenated string sss
        for (int i = 0; i < ns; i++) {
            o = true;
            for (m = 0; m < nt; m++) {
                if (t.charAt(m) != sss.charAt(i + m)) { // Compare characters
                    o = false;
                    break;
                }
            }
            ok[i] = o; // Store the result of the match
            if (o) {
                i += nt - mp.table[m]; // Update index based on the pattern table
                m = mp.table[m]; // Update match index
            }
            for (m = 0; m >= 0 && t.charAt(m) != sss.charAt(i + m); m = mp.table[m]) {
                i += m - mp.table[m]; // Update index if mismatch occurs
            }
            i--; // Adjust index for the next iteration
            m++; // Move to the next character
        }

        // Calculate the answer based on the matches found
        int ans = 0;
        int r, rr;
        for (int i = 0; i < ns; i++) {
            if (ok[i] == false) {
                continue; // Skip if no match
            }
            if (ok[(i + nt) % ns] == false) {
                continue; // Skip if no match for the next index
            }
            r = root(i, uni); // Find the root of the current index
            rr = root((i + nt) % ns, uni); // Find the root of the next index
            if (rr == r) {
                System.out.println(-1); // Output -1 if they are in the same component
                return;
            }
            uni[rr] = r; // Union the two components
        }

        // Count the number of matches for each unique root
        int[] counter = new int[ns];
        for (int i = 0; i < ns; i++) {
            r = root(i, uni); // Find the root for the current index
            if (ok[r] == false) {
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
        System.out.println(ans);

        writer.flush(); // Flush the writer to ensure all output is written
    }

    // root function finds the root of the given index using path compression.
    public static int root(int i, int[] uni) {
        if (i == uni[i]) {
            return i; // Return if the index is its own root
        }

        uni[i] = root(uni[i], uni); // Path compression
        return uni[i]; // Return the root
    }

    // MP struct holds the string and its pattern matching table.
    public static class MP {

        public String s;
        public int[] table;

        // init initializes the pattern matching table for the string.
        public void init(String s) {
            this.s = s;
            int n = s.length();
            int[] table = new int[n + 1];
            table[0] = -1; // Initialize the first value of the table
            int j = -1;
            for (int i = 0; i < n; i++) {
                for (j = 0; j >= 0 && s.charAt(i) != s.charAt(j); j = table[j]) {
                    j = table[j]; // Update j based on the table
                }
                j++;
                table[i + 1] = j; // Fill the table with the length of the longest prefix
            }
            this.table = table; // Assign the completed table to the MP struct
        }
    }

    // Scanner struct holds the scanner for reading input.
    public static class Scanner {

        private BufferedReader scanner;

        // getScanner initializes a new scanner for reading from the provided file pointer.
        public Scanner(BufferedReader fp) {
            scanner = fp;
        }

        // getNextString retrieves the next string from the scanner.
        public String getNextString() throws IOException {
            scanner.mark(1000000); // Set the buffer size for the scanner
            scanner.skip("\\s+"); // Skip any whitespace
            String s = scanner.readLine(); // Read the next token
            scanner.reset(); // Reset the scanner
            return s; // Return the scanned text
        }
    }

    // Writer struct holds the writer for output.
    public static class Writer {

        private BufferedReader writer;

        // getWriter initializes a new writer for writing to the provided file pointer.
        public Writer(BufferedReader fp) {
            writer = fp;
        }

        // flush flushes the writer to ensure all output is written.
        public void flush() throws IOException {
            writer.flush(); // Flush the writer
        }
    }
}

