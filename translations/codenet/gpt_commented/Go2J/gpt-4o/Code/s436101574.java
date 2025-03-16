import java.util.*;
import java.io.*;

public class Main {
    // Initialize scanner and writer for input and output
    static Scanner sc = new Scanner(System.in);
    static PrintWriter wr = new PrintWriter(System.out);

    // Function to read a single string from input
    static String scanString() {
        return sc.next();
    }

    // Function to read a single integer from input
    static int scanInt() {
        return Integer.parseInt(scanString());
    }

    // Function to read a single long from input
    static long scanLong() {
        return Long.parseLong(scanString());
    }

    // Function to read a single double from input
    static double scanDouble() {
        return Double.parseDouble(scanString());
    }

    // Function to read n integers from input and return them as an array
    static int[] scanInts(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = scanInt();
        }
        return res;
    }

    // Function to return the absolute value of an integer
    static int abs(int a) {
        return a < 0 ? -a : a;
    }

    // Function to return the minimum of two integers
    static int min(int a, int b) {
        return a < b ? a : b;
    }

    // Function to return the maximum of two integers
    static int max(int a, int b) {
        return a > b ? a : b;
    }

    // Main function where the program execution begins
    public static void main(String[] args) {
        // Read the first string of characters (s)
        String s = scanString();
        // Read the second string of characters (t)
        String t = scanString();

        // Initialize a list to hold possible answers
        List<String> ans = new ArrayList<>();

        // Iterate through the first string to find occurrences of the second string
        for (int i = 0; i <= s.length() - t.length(); i++) {
            boolean f = true; // Flag to check if the current position is valid
            char[] ss = s.toCharArray(); // Create a copy of the original string

            // Check if the substring of s can match t
            for (int j = 0; j < t.length(); j++) {
                // If characters do not match and are not '?', set flag to false
                if (s.charAt(i + j) != t.charAt(j) && s.charAt(i + j) != '?') {
                    f = false;
                    break;
                } else {
                    // Replace '?' with the corresponding character from t
                    ss[i + j] = t.charAt(j);
                }
            }
            // If the substring matched, replace remaining '?' with 'a' and store the result
            if (f) {
                for (int k = 0; k < ss.length; k++) {
                    if (ss[k] == '?') {
                        ss[k] = 'a';
                    }
                }
                ans.add(new String(ss));
            }
        }

        // Sort the possible answers
        Collections.sort(ans);

        // Output the result: either the first valid answer or "UNRESTORABLE"
        if (ans.isEmpty()) {
            wr.println("UNRESTORABLE");
        } else {
            wr.println(ans.get(0));
        }

        // Ensure the writer flushes its content before exiting
        wr.flush();
    }
}
// <END-OF-CODE>
