
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
    final static int INF = 1000000000;
    final static int NIL = -1;

    // for dijkstra, prim, and so on
    final static int WHITE = 0;
    final static int GRAY  = 1;
    final static int BLACK = 2;

    static {
        // bufio.ScanWords <---> bufio.ScanLines
        ReadString = new ReadString(System.in, Scanner. delims);
        stdout = new PrintWriter(System.out);
    }

    static int a, b, c;
    static int k;

    public static void main(String[] args) {
        a = ReadInt();
        b = ReadInt();
        c = ReadInt();
        k = ReadInt();

        List<List<Integer>> patterns = DuplicatePatterns(Arrays.asList(0, 1, 2, 3), k);

        for (List<Integer> P : patterns) {
            int r = a, g = b, b_ = c;
            for (int i = 0; i < P.size(); i++) {
                if (P.get(i) == 0) {
                    continue;
                } else if (P.get(i) == 1) {
                    r *= 2;
                } else if (P.get(i) == 2) {
                    g *= 2;
                } else if (P.get(i) == 3) {
                    b_ *= 2;
                }
            }

            if (g > r && b_ > g) {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }

    // DuplicatePatterns returns all patterns of n^k of elems([]int).
    static List<List<Integer>> DuplicatePatterns(List<Integer> elems, int k) {
        return dupliRec(new ArrayList<Integer>(), elems, k);
    }

    // DFS function for DuplicatePatterns.
    static List<List<Integer>> dupliRec(List<Integer> pattern, List<Integer> elems, int k) {
        if (pattern.size() == k) {
            return Arrays.asList(pattern);
        }

        List<List<Integer>> res = new ArrayList<>();
        for (int e : elems) {
            List<Integer> newPattern = new ArrayList<>(pattern);
            newPattern.add(e);

            res.addAll(dupliRec(newPattern, elems, k));
        }

        return res;
    }

    /*********** I/O ***********/

    static Scanner ReadString;
    static PrintWriter stdout;

    static class ReadString {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        // Read string from stdin. Delimiter is set by delimiter argument.
        // delimiter should be set by String's delimiter.
        ReadString(InputStream is, String delimiter) {
            reader = new BufferedReader(new InputStreamReader(is));
            tokenizer = new StringTokenizer("", delimiter);
        }

        String next() {
            while (!tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }

            return tokenizer.nextToken();
        }
    }

    // ReadInt returns an integer.
    static int ReadInt() {
        return Integer.parseInt(ReadString.next());
    }
    static int ReadInt2() {
        return Integer.parseInt(ReadString.next());
    }
    static int ReadInt3() {
        return Integer.parseInt(ReadString.next());
    }
    static int ReadInt4() {
        return Integer.parseInt(ReadString.next());
    }

    // ReadInt64 returns as integer as int64.
    static long ReadInt64() {
        return Long.parseLong(ReadString.next());
    }
    static long ReadInt64_2() {
        return Long.parseLong(ReadString.next());
    }
    static long ReadInt64_3() {
        return Long.parseLong(ReadString.next());
    }
    static long ReadInt64_4() {
        return Long.parseLong(ReadString.next());
    }

    // ReadIntSlice returns an integer slice that has n integers.
    static int[] ReadIntSlice(int n) {
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = ReadInt();
        }
        return b;
    }

    // ReadInt64Slice returns as int64 slice that has n integers.
    static long[] ReadInt64Slice(int n) {
        long[] b = new long[n];
        for (int i = 0; i < n; i++) {
            b[i] = ReadInt64();
        }
        return b;
    }

    // ReadFloat64 returns an float64.
    static double ReadFloat64() {
        return Double.parseDouble(ReadString.next());
    }

    // ReadFloat64Slice returns an float64 slice that has n float64.
    static double[] ReadFloat64Slice(int n) {
        double[] b = new double[n];
        for (int i = 0; i < n; i++) {
            b[i] = ReadFloat64();
        }
        return b;
    }

    // ReadruneSlice returns a rune slice.
    static char[] ReadruneSlice() {
        return ReadString.next().toCharArray();
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

        char[] res = new char[zeros.length + sn.length()];
        int i;
        for (i = 0; i < zeros.length; i++) {
            res[i] = zeros[i];
        }
        for (int j = 0; j < sn.length(); j++, i++) {
            res[i] = sn.charAt(j);
        }

        return res;
    }

    // Strtoi is a wrapper of strconv.Atoi().
    // If strconv.Atoi() returns an error, Strtoi calls panic.
    static int Strtoi(String s) {
        if (s == null) {
            throw new NumberFormatException("null");
        }
        try {
            return Integer.parseInt(s);
        } catch (NumberFormatException e) {
            throw new NumberFormatException("For input string: \"" + s + "\"");
        }
    }

    // PrintIntsLine returns integers string delimited by a space.
    static String PrintIntsLine(int... A) {
        StringBuilder sb = new StringBuilder(128);

        for (int i = 0; i < A.length; i++) {
            sb.append(A[i]);
            if (i!= A.length - 1) {
                sb.append(' ');
            }
        }

        return sb.toString();
    }

    // PrintIntsLine returns integers string delimited by a space.
    static String PrintInts64Line(long... A) {
        StringBuilder sb = new StringBuilder(128);

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
}
