import java.util.*;
import java.io.*;

// Define a class for sorting pairs
class Pair {
    long index;
    Object p1, p2;

    Pair(long index, Object p1, Object p2) {
        this.index = index;
        this.p1 = p1;
        this.p2 = p2;
    }
}

// Define a class for sorting int arrays
class Int64Array {
    long[] array;

    Int64Array(long[] array) {
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

public class Main {
    // Constants for buffer sizes and infinity value
    static final int INITIAL_BUF_SIZE = 10000;
    static final int MAX_BUF_SIZE = 100000000;
    static final long INF = 100000000;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        // Read three integers A, B, C
        String[] input = reader.readLine().split(" ");
        long A = Long.parseLong(input[0]);
        long B = Long.parseLong(input[1]);
        long C = Long.parseLong(input[2]);

        // Check if C is within the range [A, B] and print the result
        if (C >= A && C <= B) {
            writer.write("Yes\n");
        } else {
            writer.write("No\n");
        }

        writer.flush();
        reader.close();
    }

    // Utility functions
    static long abs(long i) {
        return Math.abs(i);
    }

    static long max(long... a) {
        return Arrays.stream(a).max().orElse(Long.MIN_VALUE);
    }

    static long min(long... a) {
        return Arrays.stream(a).min().orElse(Long.MAX_VALUE);
    }

    static long sum(long[] i) {
        return Arrays.stream(i).sum();
    }

    static String[] split(String s) {
        return s.split("\\s+");
    }

    static long[] strArrayToIntArray(String[] strs) {
        return Arrays.stream(strs).mapToLong(Long::parseLong).toArray();
    }

    static String[] intArrayToStrArray(long[] nums) {
        return Arrays.stream(nums).mapToObj(String::valueOf).toArray(String[]::new);
    }

    static String arrayToString(String[] strs) {
        return String.join(" ", strs);
    }

    static long[] reverse(long[] res) {
        for (int i = 0, j = res.length - 1; i < j; i++, j--) {
            long temp = res[i];
            res[i] = res[j];
            res[j] = temp;
        }
        return res;
    }

    static String[] reverseStr(String[] res) {
        for (int i = 0, j = res.length - 1; i < j; i++, j--) {
            String temp = res[i];
            res[i] = res[j];
            res[j] = temp;
        }
        return res;
    }
}

// <END-OF-CODE>
