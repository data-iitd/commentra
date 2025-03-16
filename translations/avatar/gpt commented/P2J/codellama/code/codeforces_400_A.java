
import java.io.*;
import java.util.*;
import java.math.*;

// Function to read a single line of input and convert it to a tuple of integers
public static int[] value() {
    String[] s = instr().split(" ");
    int[] a = new int[s.length];
    for (int i = 0; i < s.length; i++) {
        a[i] = Integer.parseInt(s[i]);
    }
    return a;
}

// Function to read a single line of input from stdin and convert it to a tuple of integers
public static int[] values() {
    String[] s = instr().split(" ");
    int[] a = new int[s.length];
    for (int i = 0; i < s.length; i++) {
        a[i] = Integer.parseInt(s[i]);
    }
    return a;
}

// Function to read a single line of input and return a list of integers
public static int[] inlst() {
    String[] s = instr().split(" ");
    int[] a = new int[s.length];
    for (int i = 0; i < s.length; i++) {
        a[i] = Integer.parseInt(s[i]);
    }
    return a;
}

// Function to read a single line of input from stdin and return a list of integers
public static int[] inlsts() {
    String[] s = instr().split(" ");
    int[] a = new int[s.length];
    for (int i = 0; i < s.length; i++) {
        a[i] = Integer.parseInt(s[i]);
    }
    return a;
}

// Function to read a single integer from input
public static int inp() {
    return Integer.parseInt(instr());
}

// Function to read a single integer from stdin
public static int inps() {
    return Integer.parseInt(instr());
}

// Function to read a single line of input and return it as a string
public static String instr() {
    return new BufferedReader(new InputStreamReader(System.in)).readLine();
}

// Function to read a single line of input and return it as a list of strings
public static String[] stlst() {
    return instr().split(" ");
}

// Helper function to determine if a specific arrangement is possible
public static boolean help(int a, int b, int[] l) {
    int[][] tot = new int[b][a];
    // Create sublists of length 'a' from the list 'l'
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            tot[i][j] = l[i * a + j];
        }
    }
    
    // Check if any combination of the sublists sums to 'b'
    for (int i = 0; i < a; i++) {
        int sum = 0;
        for (int j = 0; j < b; j++) {
            sum += tot[j][i];
        }
        if (sum == b) {
            return true;
        }
    }
    return false;
}

// Main function to solve the problem
public static void solve() {
    int[] tot = new int[1000000];
    String x = instr();  // Read the input string
    int[] s = new int[x.length()];
    
    // Convert the input string into a list of integers (0 for 'O', 1 for 'X')
    for (int i = 0; i < x.length(); i++) {
        if (x.charAt(i) == 'O') {
            s[i] = 0;
        } else {
            s[i] = 1;
        }
    }
    
    // Check for all divisors of 12 to find valid arrangements
    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) {  // Check if 'i' is a divisor of 12
            if (help(i, 12 / i, s)) {  // Use the helper function to check arrangements
                tot[i] = 1;  // Store valid arrangements as tuples
            }
        }
    }
    
    // Print the number of valid arrangements
    System.out.print(tot.length + " ");
    
    // Print each valid arrangement in sorted order
    for (int i = 1; i <= 12; i++) {
        if (tot[i] == 1) {
            System.out.print(i + "x" + (12 / i) + " ");
        }
    }
    System.out.println();  // Print a newline at the end
}

// Entry point of the program
public static void main(String[] args) {
    // Read the number of test cases and solve each case
    for (int i = 0; i < inp(); i++) {
        solve();
    }
}

