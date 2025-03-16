import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.lang.Character.Subset;
import java.math.BigDecimal;
import java.text.DecimalFormat;
import java.time.temporal.ValueRange;
import java.util.AbstractMap;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Objects;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.concurrent.ForkJoinPool;

import static java.util.Comparator.*;

public class Main {

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyInput in = new MyInput(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        Solver solver = new Solver(in, out);
        solver.solve();

        out.close();
    }

    // ======================================================================
    static class Solver {
    	MyInput in;
    	PrintWriter out;
        public Solver(MyInput in, PrintWriter out) {
        	this.in = in;
        	this.out = out;
        }

        // -----------------------------------------
        public void solve() {
        	int H = ni(); // Read height H from input
        	int W = ni(); // Read width W from input
        	char[][] C = new char[H+2][W+2]; // Create a 2D char array C of size (H+2)x(W+2)
        	char[] c; // A temporary char array c
        	for (int i = 0; i < H; i++) { // Read each line of input
        		c = ns().toCharArray(); // Read a line as a char array c
        		for (int j = 0; j < W; j++) { // Store each character in the 2D char array C
        			C[i+1][j+1] = c[j];
        		}
        	}
        	// Check some conditions
        	if(H == 1 && W == 1) {
        		prn("No");
        		return;
        	}
        	for (int i = 1; i <= H; i++) { // Check each cell in the 2D char array C
        		for (int j = 1; j <= W; j++) {
        			if(C[i][j] == '#' && C[i-1][j] != '#' && C[i+1][j] != '#' 
        								&& C[i][j-1] != '#' && C[i][j+1] != '#' ) {
        				prn("No");
        				return;
        			}
        		}
        	}
        	prn("Yes"); // If all conditions are met, print "Yes"
        }

        // -----------------------------------------
        // Helper methods
        void prn(String s) { // Print a string to the output
        	out.println(s);
        }
        void prn(int i) { // Print an integer to the output
        	out.println(i);
        }
        void prn(long i) { // Print a long integer to the output
        	out.println(i);
        }
        void prr(String s) { // Print a string to the output without a newline
        	out.print(s);
        }
        int ni() { // Read an integer from the input
        	return in.nextInt();
        }
        long nl() { // Read a long integer from the input
        	return in.nextLong();
        }
        double nd() { // Read a double from the input
        	return in.nextDouble();
        }
        String ns() { // Read a string from the input
        	return in.nextString();
        }
        int[] ndi(int n) { // Read n integers from the input and return an integer array
        	int[] ans = new int[n];
        	for(int i=0; i < n; i++) {
        		ans[i] = ni();
        	}
        	return ans;
        }
        long[] ndl(int n) { // Read n long integers from the input and return a long integer array
        	long[] ans = new long[n];
        	for(int i=0; i < n; i++) {
        		ans[i] = nl();
        	}
        	return ans;
        }
        double[] ndd(int n) { // Read n doubles from the input and return a double array
        	double[] ans = new double[n];
        	for(int i=0; i < n; i++) {
        		ans[i] = nd();
        	}
        	return ans;
        }
        String[] nds(int n) { // Read n strings from the input and return a string array
        	String[] ans = new String[n];
        	for(int i=0; i < n; i++) {
        		ans[i] = ns();
        	}
        	return ans;
        }
        int[][] nddi(int n, int m) { // Read nxm integers from the input and return a 2D integer array
        	int[][] ans = new int[n][m];
        	for(int i=0; i < n; i++) {
            	for(int j=0; j < m; j++) {
            		ans[i][j] = ni();
            	}
        	}
        	return ans;
        }
        long[][] nddl(int n, int m) { // Read nxm long integers from the input and return a 2D long integer array
        	long[][] ans = new long[n][m];
        	for(int i=0; i < n; i++) {
            	for(int j=0; j < m; j++) {
            		ans[i][j] = nl();
            	}
        	}
        	return ans;
        }
    }
    // ======================================================================
}