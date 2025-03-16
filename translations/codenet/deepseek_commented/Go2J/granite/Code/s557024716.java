
/*
URL:
https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_b
*/

import java.io.*;
import java.util.*;

/********** FAU standard libraries **********/

//fmt.Sprintf("%b\n", 255) 	// binary expression

/********** I/O usage **********/

//str := ReadString()
//i := ReadInt()
//X := ReadIntSlice(n)
//S := ReadruneSlice()
//a := ReadFloat64()
//A := ReadFloat64Slice(n)

//str := ZeroPaddingRuneSlice(num, 32)
//str := PrintIntsLine(X...)

/*******************************************************************/

public class s557024716{
    final static long MOD = 1000000000L + 7;
    final static int ALPHABET_NUM = 26;
    final static long INF_LONG = 100000000000000000L;
    final static int INF_INT = 1000000000;
    final static long NIL = -1;

    // init() initializes the input reader and output writer.
    static {
        // bufio.ScanWords <---> bufio.ScanLines
        ReadString = new ReadString(System.in, Scanner.TokenType.WORD);
        stdout = new PrintWriter(System.out);
    }

    // Global variables for the problem.
    static int a, b, c;
    static int k;

    // main function reads inputs, generates patterns, and checks the condition.
    public static void main(String[] args) {
        a = ReadInt();
        b = ReadInt();
        c = ReadInt();
        k = ReadInt();

        // Generate all possible patterns of length k where each element is one of 0, 1, 2, or 3.
        List<List<Integer>> patterns = duplicatePatterns(Arrays.asList(0, 1, 2, 3), k);

        // Iterate through each pattern to check the condition.
        for (List<Integer> P : patterns) {
            int r = a, g = b, _ = c; // Initialize r, g, and b with a, b, and c respectively.
            for (int i = 0; i < P.size(); i++) {
                if (P.get(i) == 0) {
                    continue; // If the operation is 0, do nothing.
                } else if (P.get(i) == 1) {
                    r *= 2; // Double the value of r.
                } else if (P.get(i) == 2) {
                    g *= 2; // Double the value of g.
                } else if (P.get(i) == 3) {
                    _ *= 2; // Double the value of _.
                }
            }

            // Check if the condition b > a and c > b is met.
            if (g > r && _ > g) {
                System.out.println("Yes"); // Print "Yes" if the condition is met.
                return;
            }
        }
        System.out.println("No"); // Print "No" if no pattern meets the condition.
    }

    // DuplicatePatterns generates all patterns of n^k of elems(List<Integer>).
    static List<List<Integer>> duplicatePatterns(List<Integer> elems, int k) {
        return dupliRec(new ArrayList<>(), elems, k);
    }

    // DFS function for DuplicatePatterns.
    static List<List<Integer>> dupliRec(List<Integer> pattern, List<Integer> elems, int k) {
        if (pattern.size() == k) {
            return Arrays.asList(pattern); // Return the pattern if its length equals k.
        }

        List<List<Integer>> res = new ArrayList<>();
        for (Integer e : elems) {
            List<Integer> newPattern = new ArrayList<>(pattern);
            newPattern.add(e); // Add the current element to the pattern.

            res.addAll(dupliRec(newPattern, elems, k)); // Recursively generate patterns.
        }

        return res;
    }

    /*********** I/O ***********/

    static Scanner ReadString;
    static PrintWriter stdout;

    // newReadString initializes a new scanner and returns a function that reads a string.
    static class ReadString {
        private final BufferedReader reader;
        private final Queue<String> queue = new LinkedList<>();
        private final int tokenType;

        ReadString(InputStream in, int tokenType) {
            reader = new BufferedReader(new InputStreamReader(in));
            this.tokenType = tokenType;
        }

        String next() {
            if (queue.isEmpty()) {
                try {
                    String line = reader.readLine();
                    if (line!= null) {
                        String[] tokens = line.split(" ");
                        queue.addAll(Arrays.asList(tokens));
                    }
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return queue.poll();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            if (queue.isEmpty()) {
                try {
                    String line = reader.readLine();
                    if (line!= null) {
                        queue.add(line);
                    }
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return queue.poll();
        }
    }

    // ReadInt returns an integer.
    static int ReadInt() {
        return ReadString.nextInt();
    }

    // ReadInt2 returns an integer pair.
    static int[] ReadInt2() {
        return new int[]{ReadString.nextInt(), ReadString.nextInt()};
    }

    // ReadInt3 returns an integer triple.
    static int[] ReadInt3() {
        return new int[]{ReadString.nextInt(), ReadString.nextInt(), ReadString.nextInt()};
    }

    // ReadInt4 returns an integer quadruple.
    static int[] ReadInt4() {
        return new int[]{ReadString.nextInt(), ReadString.nextInt(), ReadString.nextInt(), ReadString.nextInt()};
    }

    // ReadInt64 returns an integer as int64.
    static long ReadInt64() {
        return ReadString.nextLong();
    }

    // ReadInt64_2 returns an int64 pair.
    static long[] ReadInt64_2() {
        return new long[]{ReadString.nextLong(), ReadString.nextLong()};
    }

    // ReadInt64_3 returns an int64 triple.
    static long[] ReadInt64_3() {
        return new long[]{ReadString.nextLong(), ReadString.nextLong(), ReadString.nextLong()};
    }

    // ReadInt64_4 returns an int64 quadruple.
    static long[] ReadInt64_4() {
        return new long[]{ReadString.nextLong(), ReadString.nextLong(), ReadString.nextLong(), ReadString.nextLong()};
    }

    // ReadFloat6 returns an float64.
    static double ReadFloat6() {
        return ReadString.nextDouble();
    }

    // ReadFloat6Slice returns an float64 slice that has n float64.
    static double[] ReadFloat6Slice(int n) {
        double[] a = new double[n];
        for (int i = 0; i < n; i++) {
            a[i] = ReadString.nextDouble();
        }
        return a;
    }

    // ReadruneSlice returns a rune slice.
    static char[] ReadruneSlice() {
        return ReadString.nextLine().toCharArray();
    }

    /*********** Debugging ***********/

    // ZeroPaddingRuneSlice returns binary expressions of integer n with zero padding.
    // For debugging use.
    static char[] ZeroPaddingRuneSlice(int n, int digitsNum) {
        String sn = Integer.toBinaryString(n);

        int residualLength = digitsNum - sn.length();
        if (residualLength <= 0) {
            return sn.toCharArray();
        }

        char[] zeros = new char[residualLength];
        Arrays.fill(zeros, '0');

        char[] res = new char[residualLength + sn.length()];
        int index = 0;
        for (int i = 0; i < residualLength; i++) {
            res[index++] = zeros[i];
        }
        for (int i = 0; i < sn.length(); i++) {
            res[index++] = sn.charAt(i);
        }

        return res;
    }

    // Strtoi is a wrapper of strconv.Atoi().
    // If strconv.Atoi() returns an error, Strtoi calls panic.
    static int Strtoi(String s) {
        if (s == null) {
            throw new NumberFormatException();
        }
        try {
            return Integer.parseInt(s);
        } catch (NumberFormatException e) {
            throw new NumberFormatException();
        }
    }

    // PrintIntsLine returns integers string delimited by a space.
    static String PrintIntsLine(int... A) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < A.length; i++) {
            sb.append(A[i]);
            if (i!= A.length - 1) {
                sb.append(' ');
            }
        }
        return sb.toString();
    }

    // PrintIntsLine returns integers string delimited by a space.
    static String PrintInts64Line(int... A) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < A.length; i++) {
            sb.append(A[i]);
            if (i!= A.length - 1) {
                sb.append(' ');
            }
        }
        return sb.toString();
    }

    // PrintfDebug is wrapper of fmt.Fprintf(os.Stderr, format, a...)
    static void PrintfDebug(String format, Object... a) {
        System.err.printf(format, a);
    }

    // PrintfBufStdout is function for output strings to buffered os.Stdout.
    // You may have to call stdout.Flush() finally.
    static void PrintfBufStdout(String format, Object... a) {
        stdout.printf(format, a);
    }
*/

package main

import "bufio"
import "fmt"
import "os"

/********** FAU standard libraries **********/

// ReadString initializes a new scanner and returns a function that reads a string.
func newReadString(ior io.Reader, sf bufio.SplitFunc) func() string {
	r := bufio.NewScanner(ior)
	r.Buffer(make([]byte, 1024), int(1e+9)) // for Codeforces
	r.Split(sf)

	return func() string {
		if!r.Scan() {
			panic("Scan failed")
		}
		return r.Text()
	}

// ReadInt returns an integer.
func ReadInt() int {
	return int(<fim_middle>*/

// newReadString initializes a new scanner and returns a function that reads a string.
func newReadString(ior io.Reader, sf bufio.SplitFunc) func() string {
	r := bufio.NewReader(ior)
	r.Buffer(make([]byte, 1024), int(1e+9)) // for Codeforces
	return func() string {
		if!r.Scan() {
			panic(errors.New("[argument erro