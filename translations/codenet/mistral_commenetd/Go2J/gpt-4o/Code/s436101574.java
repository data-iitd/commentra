import java.util.*;
import java.io.*;

public class Main {
    // Initializing scanner and writer
    static Scanner sc = new Scanner(System.in);
    static PrintWriter wr = new PrintWriter(System.out);

    // Function to read a single string
    static String scanString() {
        return sc.next();
    }

    // Function to read a single integer
    static int scanInt() {
        return Integer.parseInt(scanString());
    }

    // Function to read multiple integers
    static int[] scanInts(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = scanInt();
        }
        return res;
    }

    // Function to get absolute value of an integer
    static int abs(int a) {
        return a < 0 ? -a : a;
    }

    // Function to get minimum of two integers
    static int min(int a, int b) {
        return a < b ? a : b;
    }

    // Function to get maximum of two integers
    static int max(int a, int b) {
        return a > b ? a : b;
    }

    // Main function
    public static void main(String[] args) {
        // Reading input strings s and t
        String s = scanString();
        String t = scanString();

        // Initializing a list to store answers
        List<String> ans = new ArrayList<>();

        // Iterating through all possible substrings of s that have the same length as t
        for (int i = 0; i <= s.length() - t.length(); i++) {
            // Initializing a StringBuilder to store the modified string s
            StringBuilder ss = new StringBuilder(s);

            // Checking if the current substring matches the pattern t
            boolean f = true;
            for (int j = 0; j < t.length(); j++) {
                // If the current character of s does not match the current character of t or is not '?'
                if (ss.charAt(i + j) != t.charAt(j) && ss.charAt(i + j) != '?') {
                    // Setting flag to false and breaking the loop
                    f = false;
                    break;
                } else {
                    // Replacing the current character of s with the corresponding character of t
                    ss.setCharAt(i + j, t.charAt(j));
                }
            }
            // If the current substring matches the pattern t
            if (f) {
                // Replacing all '?' with 'a' in the modified string
                String modifiedString = ss.toString().replace("?", "a");
                ans.add(modifiedString);
            }
        }
        // Sorting the answer list in ascending order
        Collections.sort(ans);
        // Checking if the answer list is empty
        if (ans.isEmpty()) {
            // Printing "UNRESTORABLE" if the answer list is empty
            wr.println("UNRESTORABLE");
        } else {
            // Printing the first element of the answer list
            wr.println(ans.get(0));
        }
        wr.flush(); // Flush the writer
    }
}
// <END-OF-CODE>
