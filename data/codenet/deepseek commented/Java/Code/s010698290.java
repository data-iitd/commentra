import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
// import java.util.Scanner;
// import java.util.Arrays;
// import java.util.ArrayList;
// import java.util.Collections; 
// import java.util.StringTokenizer;
import java.util.*;
import java.lang.Math;
import java.awt.Point;

import java.awt.geom.*;

public class Main {

    public static void main(String args[]) {
        try {
            FastReader s = new FastReader(); // Initialize FastReader for input
            BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out)); // Initialize BufferedWriter for output
            int i, j;
            int m, n, t, max, k, x, y, min, correct_ans, num, num_penal;
            long a, b, sum;

            String str;

            n = s.nextInt(); // Read number of participants
            m = s.nextInt(); // Read number of submissions

            int penal[] = new int[n+1]; // Array to store penalty points for each participant
            boolean solved[] = new boolean[n+1]; // Array to track if a participant has solved a problem
            Arrays.fill(solved, false); // Initialize all participants as not solved

            for(i=0; i<m; i++){ // Process each submission
                num = s.nextInt(); // Read the problem number
                str = s.next(); // Read the submission result
                if(str.charAt(0) == 'A'){ // Check if the submission is correct
                    solved[num] = true; // Mark the problem as solved
                }else
                    if(solved[num] == false) // Check if the problem is not yet solved
                        penal[num]++; // Increment the penalty points for the problem
            }

            correct_ans = 0; // Initialize the count of correctly solved problems
            num_penal = 0; // Initialize the total penalty points
            for(i=1; i<=n; i++){ // Calculate the total number of correctly solved problems and penalty points
                if(solved[i] == true){
                    correct_ans++; // Increment the count of correctly solved problems
                    num_penal+=penal[i]; // Add the penalty points for the participant
                }

            }

            w.write(correct_ans+" "+num_penal+"\n"); // Write the results to the output
            w.close(); // Close the BufferedWriter


        } catch (Exception e) {
            e.printStackTrace(); // Print stack trace if an error occurs
        }
    }
}

// ========================================### FAST IO ###=========================================//
class FastReader {
    BufferedReader br;
    StringTokenizer st;

    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in)); // Initialize BufferedReader for input
    }

    String next() {
        while (st == null || !st.hasMoreElements()) { // Check if there are more tokens
            try {
                st = new StringTokenizer(br.readLine()); // Read a line of input
            } catch (IOException e) {
                e.printStackTrace(); // Print stack trace if an error occurs
            }
        }
        return st.nextToken(); // Return the next token
    }

    int nextInt() {
        return Integer.parseInt(next()); // Parse the next token as an integer
    }

    long nextLong() {
        return Long.parseLong(next()); // Parse the next token as a long
    }

    Double nextDouble() {
        return Double.parseDouble(next()); // Parse the next token as a double
    }

    String nextLine() {
        String str = "";
        try {
            str = br.readLine(); // Read a line of input
        } catch (IOException e) {
            e.printStackTrace(); // Print stack trace if an error occurs
        }
        return str; // Return the line of input
    }
}
// ====================================================================================================//
