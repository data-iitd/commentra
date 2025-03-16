
/*
URL:
https://atcoder.jp/contests/abc082/tasks/arc087_b
*/

package main;

import java.io.*;
import java.util.*;

/********** FAU standard libraries **********/

// fmt.Sprintf("%b\n", 255) 	// binary expression

/********** I/O usage **********/

// str := ReadString()
// i := ReadInt()
// X := ReadIntSlice(n)
// S := ReadruneSlice()
// a := ReadFloat64()
// A := ReadFloat64Slice(n)

// str := ZeroPaddingRuneSlice(num, 32)
// str := PrintIntsLine(X...)

/*******************************************************************/

// Constants for general purpose use
final int MOD = 1000000000 + 7; // Modulus value
final int ALPHABET_NUM = 26; // Number of letters in the alphabet
final int INF_INT64 = Long.MAX_VALUE; // Maximum value for int64
final int INF_BIT60 = 1 << 60; // 2^60
final int INF_INT32 = Integer.MAX_VALUE; // Maximum value for int32
final int INF_BIT30 = 1 << 30; // 2^30
final int NIL = -1; // Represents a null value

// Constants for graph algorithms like Dijkstra and Prim
final int WHITE = 0; // Unvisited state
final int GRAY = 1; // Visited state
final int BLACK = 2; // Processed state

public class s069675863{
    // Initialize custom input reading function and buffered output
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        // Read the input string and target coordinates
        char[] S = br.readLine().toCharArray();
        int x = Integer.parseInt(br.readLine());
        int y = Integer.parseInt(br.readLine());

        List<Integer> F = new ArrayList<>(); // List to hold the lengths of consecutive 'F's
        int cur = 0; // Current count of consecutive 'F's

        // Count consecutive 'F's and store in F
        for (int i = 0; i < S.length; i++) {
            if (S[i] == 'F') {
                cur++;
            } else {
                F.add(cur);
                cur = 0;
            }
        }
        F.add(cur); // Append the last count of 'F's
        //bw.write(F.toString()); // Debug output of the lengths of 'F's

        List<Integer> evens = new ArrayList<>(); // List to separate even indexed counts
        List<Integer> odds = new ArrayList<>(); // List to separate odd indexed counts
        // Separate counts into even and odd indexed slices
        for (int i = 0; i < F.size(); i++) {
            if (i % 2 == 0) {
                evens.add(F.get(i));
            } else {
                odds.add(F.get(i));
            }
        }

        // Initialize the dynamic programming tables for x and y
        boolean[][] dpx = new boolean[evens.size() + 1][20001]; // Dynamic programming table for x
        boolean[][] dpy = new boolean[odds.size() + 1][20001]; // Dynamic programming table for y

        // Fill the dynamic programming table for even indexed counts
        dpx[0][10000] = true;
        dpy[0][10000] = true;
        for (int i = 0; i < evens.size(); i++) {
            int val = evens.get(i);
            for (int j = 20000; j >= 0; j--) {
                if (j + val <= 20000) {
                    dpx[i + 1][j + val] |= dpx[i][j];
                }
                if (j - val >= 0) {
                    dpx[i + 1][j - val] |= dpx[i][j];
                }
            }
        }

        // Fill the dynamic programming table for odd indexed counts
        for (int i = 0; i < odds.size(); i++) {
            int val = odds.get(i);
            for (int j = 20000; j >= 0; j--) {
                if (j + val <= 20000) {
                    dpy[i + 1][j + val] |= dpy[i][j];
                }
                if (j - val >= 0) {
                    dpy[i + 1][j - val] |= dpy[i][j];
                }
            }
        }

        // Check if the target coordinates can be reached
        if (dpx[evens.size()][x + 10000] && dpy[odds.size()][y + 10000]) {
            bw.write("Yes\n"); // Output "Yes" if reachable
        } else {
            bw.write("No\n"); // Output "No" if not reachable
        }

        bw.flush(); // Flush the output buffer
    }
}

/*
