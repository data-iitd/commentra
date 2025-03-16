import java.io.*;
import java.util.*;

public class Main {
    // Constants for general purpose use
    static final int MOD = 1000000000 + 7; // Modulus value
    static final int ALPHABET_NUM = 26; // Number of letters in the alphabet
    static final long INF_INT64 = Long.MAX_VALUE; // Maximum value for int64
    static final int INF_INT32 = Integer.MAX_VALUE; // Maximum value for int32
    static final int NIL = -1; // Represents a null value

    static boolean[][] dpx = new boolean[8000][20000]; // Dynamic programming table for x coordinates
    static boolean[][] dpy = new boolean[8000][20000]; // Dynamic programming table for y coordinates

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine(); // Read the input string
        String[] coords = br.readLine().split(" ");
        int x = Integer.parseInt(coords[0]);
        int y = Integer.parseInt(coords[1]);

        List<Integer> F = new ArrayList<>(); // List to hold the lengths of consecutive 'F's
        int cur = 0; // Current count of consecutive 'F's

        // Count consecutive 'F's and store in F
        for (char c : S.toCharArray()) {
            if (c == 'F') {
                cur++;
            } else {
                F.add(cur);
                cur = 0;
            }
        }
        F.add(cur); // Append the last count of 'F's

        List<Integer> evens = new ArrayList<>(), odds = new ArrayList<>(); // Lists to separate even and odd indexed counts
        // Separate counts into even and odd indexed lists
        for (int i = 0; i < F.size(); i++) {
            if (i % 2 == 0) {
                evens.add(F.get(i));
            } else {
                odds.add(F.get(i));
            }
        }

        // Initialize the dynamic programming tables for x and y
        dpx[0][10000] = true;
        dpy[0][10000] = true;

        // Fill the dynamic programming table for even indexed counts
        for (int i = 0; i < evens.size(); i++) {
            int val = evens.get(i);
            for (int j = 2000; j <= 18000; j++) {
                if (j + val <= 18000) {
                    dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
                }
                if (j - val >= 2000 && i != 0) {
                    dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
                }
            }
        }

        // Fill the dynamic programming table for odd indexed counts
        for (int i = 0; i < odds.size(); i++) {
            int val = odds.get(i);
            for (int j = 2000; j <= 18000; j++) {
                if (j + val <= 18000) {
                    dpy[i + 1][j + val] = dpy[i + 1][j + val] || dpy[i][j];
                }
                if (j - val >= 2000) {
                    dpy[i + 1][j - val] = dpy[i + 1][j - val] || dpy[i][j];
                }
            }
        }

        // Check if the target coordinates can be reached
        if (dpx[evens.size()][x + 10000] && dpy[odds.size()][y + 10000]) {
            System.out.println("Yes"); // Output "Yes" if reachable
        } else {
            System.out.println("No"); // Output "No" if not reachable
        }
    }
}

/* <END-OF-CODE> */
