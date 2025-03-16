
/*
URL:
https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_b
*/

package main;

import java.io.*;
import java.util.*;

/********** FAU standard libraries **********/

// Examples of reading various types of input
// String str = ReadString();
// int i = ReadInt();
// int[] X = ReadIntArray(n);
// char[] S = ReadruneArray();
// double a = ReadFloat64();
// double[] A = ReadFloat64Array(n);

// Examples of formatting output
// String str = ZeroPaddingruneArray(num, 32);
// String str = PrintIntsLine(X...);

/*******************************************************************/

// Constants for general use
final int MOD = 1000000000 + 7; // Modulus value for calculations
final int ALPHABET_NUM = 26; // Number of letters in the alphabet
final long INF_LONG = 1L << 60; // 60-bit integer limit
final int INF_INT = 1000000000; // Maximum value for int
final int NIL = -1; // Nil value for error handling

// Constants for graph algorithms (Dijkstra, Prim, etc.)
final int WHITE = 0; // Unvisited node
final int GRAY = 1; // Visited but not fully explored
final int BLACK = 2; // Fully explored node

public class s557024716{
    public static void main(String[] args) throws IOException {
        // Read three integers and the number of patterns
        int a = ReadInt();
        int b = ReadInt();
        int c = ReadInt();
        int k = ReadInt();

        // Generate all possible patterns of length k from the set {0, 1, 2, 3}
        List<int[]> patterns = duplicatePatterns(new int[]{0, 1, 2, 3}, k);

        // Iterate through each generated pattern
        for (int[] P : patterns) {
            int r = a; // Initialize color values for each pattern
            int g = b;
            int bb = c;
            // Apply the pattern to modify the color values
            for (int i = 0; i < P.length; i++) {
                if (P[i] == 0) {
                    continue; // Skip if the pattern element is 0
                } else if (P[i] == 1) {
                    r *= 2; // Double the red value
                } else if (P[i] == 2) {
                    g *= 2; // Double the green value
                } else if (P[i] == 3) {
                    bb *= 2; // Double the blue value
                }
            }

            // Check if the modified values satisfy the condition
            if (g > r && bb > g) {
                System.out.println("Yes"); // Print "Yes" if the condition is met
                return;
            }
        }
        System.out.println("No"); // Print "No" if no pattern satisfies the condition
    }

    // Recursive function to generate patterns
    public static List<int[]> duplicatePatterns(int[] elems, int k) {
        List<int[]> res = new ArrayList<>(); // Slice to hold the results
        if (k == 0) {
            res.add(new int[]{}); // Add an empty pattern
            return res; // Return the completed pattern
        }

        for (int e : elems) {
            int[] newPattern = Arrays.copyOf(elems, k); // Create a new pattern
            newPattern[k - 1] = e; // Set the last element of the new pattern
            res.addAll(duplicatePatterns(newPattern, k - 1)); // Recursively generate patterns
        }

        return res; // Return all generated patterns
    }

    /*********** I/O ***********/

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Input reader
    static BufferedWriter stdout = new BufferedWriter(new OutputStreamWriter(System.out)); // Buffered writer for output

    // Function to create a new ReadString function with specified input reader and split function
    static String ReadString() throws IOException {
        return br.readLine(); // Read a line from input
    }

    // ReadInt returns an integer from input.
    static int ReadInt() throws IOException {
        return Integer.parseInt(ReadString()); // Parse input as int
    }

    // ReadInt2 returns two integers from input.
    static int[] ReadInt2() throws IOException {
        String[] s = ReadString().split(" "); // Split the input into two integers
        return new int[]{Integer.parseInt(s[0]), Integer.parseInt(s[1])}; // Return the two integers
    }

    // ReadInt3 returns three integers from input.
    static int[] ReadInt3() throws IOException {
        String[] s = ReadString().split(" "); // Split the input into three integers
        return new int[]{Integer.parseInt(s[0]), Integer.parseInt(s[1]), Integer.parseInt(s[2])}; // Return the three integers
    }

    // ReadInt4 returns four integers from input.
    static int[] ReadInt4() throws IOException {
        String[] s = ReadString().split(" "); // Split the input into four integers
        return new int[]{Integer.parseInt(s[0]), Integer.parseInt(s[1]), Integer.parseInt(s[2]), Integer.parseInt(s[3])}; // Return the four integers
    }

    // Function to read an int64 from input and handle errors
    static long ReadInt64() throws IOException {
        return Long.parseLong(ReadString()); // Parse input as long
    }

    // ReadInt64_2 returns two int64 values from input.
    static long[] ReadInt64_2() throws IOException {
        String[] s = ReadString().split(" "); // Split the input into two int64 values
        return new long[]{Long.parseLong(s[0]), Long.parseLong(s[1])}; // Return the two int64 values
    }

    // ReadInt64_3 returns three int64 values from input.
    static long[] ReadInt64_3() throws IOException {
        String[] s = ReadString().split(" "); // Split the input into three int64 values
        return new long[]{Long.parseLong(s[0]), Long.parseLong(s[1]), Long.parseLong(s[2])}; // Return the three int64 values
    }

    // ReadInt64_4 returns four int64 values from input.
    static long[] ReadInt64_4() throws IOException {
        String[] s = ReadString().split(" "); // Split the input into four int64 values
        return new long[]{Long.parseLong(s[0]), Long.parseLong(s[1]), Long.parseLong(s[2]), Long.parseLong(s[3])}; // Return the four int64 values
    }

    // ReadFloat64 returns a float64 from input.
    static double ReadFloat64() throws IOException {
        return Double.parseDouble(ReadString()); // Parse input as float64
    }

    // Function to read a float64 from input and handle errors
    static double ReadFloat64_2() throws IOException {
        return Double.parseDouble(ReadString()); // Parse input as float64
    }

    // ReadFloat64Slice returns a slice of float64 values of size n.
    static double[] ReadFloat64Slice(int n) throws IOException {
        double[] b = new double[n]; // Create a slice of size n
        for (int i = 0; i < n; i++) {
            b[i] = ReadFloat64(); // Read each float64 value into the slice
        }
        return b; // Return the slice of float64 values
    }

    // ReadRuneSlice returns a slice of runes from input.
    static char[] ReadRuneSlice() throws IOException {
        return ReadString().toCharArray(); // Convert the input string to a slice of runes
    }

    /*********** Debugging ***********/

    // ZeroPaddingRuneSlice returns binary expressions of integer n with zero padding.
    // For debugging use.
    static String ZeroPaddingRuneSlice(int n, int digitsNum) {
        String sn = Integer.toBinaryString(n); // Convert integer to binary string
        int residualLength = digitsNum - sn.length(); // Calculate how many zeros to add
        if (residualLength <= 0) {
            return sn; // Return the binary string if no padding is needed
        }

        char[] zeros = new char[residualLength]; // Create a slice for zeros
        for (int i = 0; i < len(zeros); i++ {
            zeros[i] = '0'; // Fill the slice with zeros
        }

        String res = ""; // Result string for final output
        res = strings.Join(res, zeros...) // Append zeros to the result string
        res = strings.Join(res, sn) // Append the binary string to the result string
        return res; // Return the padded binary string
    }

    // PrintIntsLine returns integers as a space-delimited string.
    static String PrintIntsLine(int... A) {
        String res = ""; // Result string for output
        for (int i = 0; i < len(A); i++ {
            str := strconv.Itoa(A[i]) // Convert each integer to string
            res = strings.Join(res, str) // Append to result string
            if i!= len(A)-1 {
                res = strings.Join(res, " ") // Add space between integers
            }
        }

        return res; // Return the final string
    }

    // PrintInts64Line returns int64 values as a space-delimited string.
    static String PrintInts64Line(int64... A) {
        String res = ""; // Result string for output
        for _, a := range A {
            str := strconv.FormatInt(a, 10) // Convert each int64 value to string
            res = strings.Join(res, " ") // Add space between int64 values
            res = strings.Join(res, str) // Append the string to the result string
            res = strings.Join(res, " ") // Append space to the result string
        }

        return res; // Return the final string
    }

    // PrintfBufStdout is a function for outputting strings to buffered os.Stdout.
    // You may have to call stdout.Flush() finally.
    static void PrintfBufStdout(format string, a...interface{}) {
        fmt.Fprintf(stdout, format, a...) // Printf to buffered os.Stdout
    }

    /*********** s557024716 Function **********/

    func main() {
        // Read three integers and the number of patterns
        a := ReadInt()
        b := ReadInt()
        c := ReadInt()
        k := ReadInt()

        // Generate all possible patterns
        patterns := duplicatePatterns([]int{0, 1, 2, 3}, k)

        // Iterate through each generated pattern
        for _, P := patterns {
            r := a
            g := b
            bb := c
            for _, p := range P {
                r *= int(P[i])
                g *= int(P[i])
                bb *= int(P[i])
                if g > r 