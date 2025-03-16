////////////////////////////////////////////////////
//                                                  //
//  For her who keeps the fire kindling in me...  //
//                                                  //
////////////////////////////////////////////////////

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
            // Initialize FastReader for efficient input reading
            FastReader s = new FastReader();
            // Initialize BufferedWriter for efficient output writing
            BufferedWriter w = new BufferedWriter(new OutputStreamWriter(System.out));
            int i, j;
            int m, n, t, max, k, x, y, min, correct_ans, num, num_penal;
            long a, b, sum;

            String str;

            // Read the number of problems (n) and the number of submissions (m)
            n = s.nextInt();
            m = s.nextInt();

            // Array to keep track of penalties for each problem
            int penal[] = new int[n+1];
            // Array to track whether each problem has been solved
            boolean solved[] = new boolean[n+1];
            // Initialize the solved array to false
            Arrays.fill(solved, false);

            // Process each submission
            for(i=0; i<m; i++){
                // Read the problem number and the result of the submission
                num = s.nextInt();
                str = s.next();
                // If the submission is accepted, mark the problem as solved
                if(str.charAt(0) == 'A'){
                    solved[num] = true;
                } else
                    // If the submission is incorrect and the problem is not solved, increment the penalty
                    if(solved[num] == false)
                        penal[num]++;
            }

            // Variables to count the number of correctly solved problems and total penalties
            correct_ans = 0;
            num_penal = 0;
            // Calculate the total number of solved problems and their penalties
            for(i=1; i<=n; i++){
                if(solved[i] == true){
                    correct_ans++;
                    num_penal += penal[i];
                }
            }

            // Write the results: number of solved problems and total penalties
            w.write(correct_ans + " " + num_penal + "\n");
            // Close the BufferedWriter
            w.close();

        } catch (Exception e) {
            // Print the stack trace in case of an exception
            e.printStackTrace();
        }
    }
}

// ========================================### FAST IO ###=========================================//
class FastReader {
    BufferedReader br;
    StringTokenizer st;

    // Constructor to initialize BufferedReader
    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    // Method to read the next token as a String
    String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                // Read a new line and tokenize it
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    // Method to read the next token as an integer
    int nextInt() {
        return Integer.parseInt(next());
    }

    // Method to read the next token as a long
    long nextLong() {
        return Long.parseLong(next());
    }

    // Method to read the next token as a double
    Double nextDouble() {
        return Double.parseDouble(next());
    }

    // Method to read the entire line as a String
    String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
}
// ====================================================================================================//
