import java.io.*;
import java.util.*;

public class Main {
    // Scanner for reading input
    private static Scanner getScanner(InputStream inputStream) {
        return new Scanner(inputStream);
    }

    // Read the next string from the scanner
    private static String getNextString(Scanner scanner) {
        return scanner.next(); // Read the next token
    }

    // Read the next integer from the scanner
    private static int getNextInt(Scanner scanner) {
        return Integer.parseInt(getNextString(scanner)); // Convert the next string to an integer
    }

    // Read the next long from the scanner
    private static long getNextLong(Scanner scanner) {
        return Long.parseLong(getNextString(scanner)); // Convert the next string to long
    }

    // Read the next double from the scanner
    private static double getNextDouble(Scanner scanner) {
        return Double.parseDouble(getNextString(scanner)); // Convert the next string to double
    }

    public static void main(String[] args) throws IOException {
        // Initialize input and output streams
        InputStream inputStream = System.in;
        PrintWriter writer = new PrintWriter(System.out);

        // Check for environment variables to override input and output
        String maspy = System.getenv("MASPY");
        String maspypy = System.getenv("MASPYPY");
        if ("ますピ".equals(maspy)) {
            inputStream = new FileInputStream(System.getenv("BEET_THE_HARMONY_OF_PERFECT")); // Open specified input file
        }
        if ("ますピッピ".equals(maspypy)) {
            writer = new PrintWriter(new FileOutputStream(System.getenv("NGTKANA_IS_GENIUS10"))); // Create specified output file
        }

        // Create a scanner for reading input
        Scanner scanner = getScanner(inputStream);

        // Read two strings from input
        String s = getNextString(scanner);
        String t = getNextString(scanner);

        // Calculate lengths of the input strings
        int ns = s.length();
        int nt = t.length();

        // Create a list to hold repeated instances of string s
        List<String> ss = new ArrayList<>(Collections.nCopies((nt - 1) / ns + 1, s));

        // Concatenate the repeated strings to form a new string
        String sss = String.join("", ss) + String.join("", ss);

        // Initialize a boolean list to track matches
        boolean[] ok = new boolean[ns];

        // Initialize a unique index array and a pattern matching structure
        int[] uni = new int[ns];
        MP mp = new MP();
        mp.init(t); // Initialize the pattern matching table with string t
        int m = 0;
        for (int i = 0; i < ns; i++) {
            uni[i] = i; // Set each index to itself initially
        }
        boolean o;

        // Check for matches of string t in the concatenated string sss
        for (int i = 0; i < ns; i++) {
            o = true;
            m = 0; // Reset m for each i
            while (m < nt) {
                if (t.charAt(m) != sss.charAt(i + m)) { // Compare characters
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
            while (m >= 0 && t.charAt(m) != sss.charAt(i + m)) {
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
                writer.println(-1); // Output -1 if they are in the same component
                writer.flush();
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
        writer.println(ans);
        writer.flush(); // Flush the writer to ensure all output is written
    }

    // root function finds the root of the given index using path compression.
    private static int root(int i, int[] uni) {
        if (i == uni[i]) {
            return i; // Return if the index is its own root
        }
        uni[i] = root(uni[i], uni); // Path compression
        return uni[i]; // Return the root
    }

    // MP class holds the string and its pattern matching table.
    static class MP {
        String s;
        int[] table;

        // init initializes the pattern matching table for the string.
        void init(String s) {
            this.s = s;
            int n = s.length();
            table = new int[n + 1];
            table[0] = -1; // Initialize the first value of the table
            int j = -1;
            for (int i = 0; i < n; i++) {
                while (j >= 0 && s.charAt(i) != s.charAt(j)) {
                    j = table[j]; // Update j based on the table
                }
                j++;
                table[i + 1] = j; // Fill the table with the length of the longest prefix
            }
        }
    }
}
// <END-OF-CODE>
