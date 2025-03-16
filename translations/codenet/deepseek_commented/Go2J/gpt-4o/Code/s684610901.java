import java.util.*;
import java.io.*;

// Package main defines the entry point for the program.

public class Main {
    /*==========================================
     *             Custom Sorting Types
     *==========================================*/
    // Pair class holds two values and an index for sorting.
    static class Pair {
        long index;
        Object p1, p2;

        Pair(long index, Object p1, Object p2) {
            this.index = index;
            this.p1 = p1;
            this.p2 = p2;
        }
    }

    // Pairs is a list of Pair objects for sorting.
    static class PairsComparator implements Comparator<Pair> {
        public int compare(Pair a, Pair b) {
            return Long.compare(a.index, b.index);
        }
    }

    // Int64Slice is a type alias for sorting lists of long.
    static class Int64Slice {
        long[] array;

        Int64Slice(long[] array) {
            this.array = array;
        }

        void sort() {
            Arrays.sort(array);
        }

        boolean isSorted() {
            for (int i = 1; i < array.length; i++) {
                if (array[i] < array[i - 1]) {
                    return false;
                }
            }
            return true;
        }
    }

    /*==========================================
     *             Constants and Variables
     *==========================================*/
    // initialBufSize and maxBufSize define the buffer sizes for scanning input.
    static final int INITIAL_BUF_SIZE = 10000;
    static final int MAX_BUF_SIZE = 100000000;
    static final long INF = 100000000;

    // scanner and writer are initialized for reading from standard input and writing to standard output.
    static Scanner scanner = new Scanner(System.in);
    static PrintWriter writer = new PrintWriter(System.out);

    /*==========================================
     *             Main Function
     *==========================================*/
    // main function reads three integers and checks if the third integer lies between the first and second.
    public static void main(String[] args) {
        long A = readInt();
        long B = readInt();
        long C = readInt();
        if (C >= A && C <= B) {
            writer.println("Yes");
        } else {
            writer.println("No");
        }
        writer.flush();
    }

    /*==========================================
     *             Library
     *==========================================*/
    // NextPermutation finds the next permutation of a list.
    static boolean nextPermutation(List<?> list) {
        int n = list.size() - 1;
        if (n < 1) {
            return false;
        }
        int j = n - 1;
        while (j >= 0 && ((Comparable) list.get(j)).compareTo(list.get(j + 1)) >= 0) {
            j--;
        }
        if (j < 0) {
            return false;
        }
        int l = n;
        while (((Comparable) list.get(j)).compareTo(list.get(l)) >= 0) {
            l--;
        }
        Collections.swap(list, j, l);
        Collections.reverse(list.subList(j + 1, n + 1));
        return true;
    }

    // doubleAry creates a 2D array initialized with a given value.
    static long[][] doubleAry(int h, int w, long init) {
        long[][] res = new long[h][w];
        for (int i = 0; i < h; i++) {
            Arrays.fill(res[i], init);
        }
        return res;
    }

    // aryEq checks if two arrays are equal.
    static boolean aryEq(long[] a, long[] b) {
        return Arrays.equals(a, b);
    }

    // clone creates a copy of an array.
    static long[] clone(long[] n) {
        return Arrays.copyOf(n, n.length);
    }

    // readInt reads an integer from the scanner.
    static long readInt() {
        return scanner.nextLong();
    }

    // abs returns the absolute value of an integer.
    static long abs(long i) {
        return Math.abs(i);
    }

    // max returns the maximum value in a list of integers.
    static long max(long... a) {
        return Arrays.stream(a).max().orElse(Long.MIN_VALUE);
    }

    // min returns the minimum value in a list of integers.
    static long min(long... a) {
        return Arrays.stream(a).min().orElse(Long.MAX_VALUE);
    }

    // sum returns the sum of an array of integers.
    static long sum(long[] i) {
        return Arrays.stream(i).sum();
    }

    // split splits a string into a list of strings.
    static String[] split(String s) {
        return s.split("\\s+");
    }

    // strAry2intAry converts a list of strings to a list of integers.
    static long[] strAry2intAry(String[] strs) {
        return Arrays.stream(strs).mapToLong(Long::parseLong).toArray();
    }

    // intAry2strAry converts a list of integers to a list of strings.
    static String[] intAry2strAry(long[] nums) {
        return Arrays.stream(nums).mapToObj(String::valueOf).toArray(String[]::new);
    }

    // reverse reverses an array of integers.
    static long[] reverse(long[] res) {
        for (int i = 0, j = res.length - 1; i < j; i++, j--) {
            long temp = res[i];
            res[i] = res[j];
            res[j] = temp;
        }
        return res;
    }

    // reverseStr reverses an array of strings.
    static String[] reverseStr(String[] res) {
        for (int i = 0, j = res.length - 1; i < j; i++, j--) {
            String temp = res[i];
            res[i] = res[j];
            res[j] = temp;
        }
        return res;
    }

    // ini initializes an array with a specific value.
    static void ini(int[] res, int init) {
        if (res.length == 0) {
            return;
        }
        res[0] = init;
        for (int i = 1; i < res.length; i++) {
            res[i] = res[0];
        }
    }
}
// <END-OF-CODE>
