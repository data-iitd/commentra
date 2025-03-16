import java.util.*;
import java.io.*;

public class Main {
    static final int INITIAL_BUF_SIZE = 10000;
    static final int MAX_BUF_SIZE = 100000000;
    static final int INF = 100000000;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(reader.readLine());
        long A = Long.parseLong(st.nextToken());
        long B = Long.parseLong(st.nextToken());
        long C = Long.parseLong(st.nextToken());

        if (C >= A && C <= B) {
            writer.write("Yes\n");
        } else {
            writer.write("No\n");
        }

        writer.flush();
    }

    /*==========================================
     *             Library
     *==========================================*/
    public static boolean nextPermutation(List<?> list) {
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

    public static long[] doubleArray(long h, long w, long init) {
        long[][] res = new long[(int) h][(int) w];
        for (int i = 0; i < h; i++) {
            Arrays.fill(res[i], init);
        }
        return res;
    }

    public static boolean arrayEquals(long[] a, long[] b) {
        return Arrays.equals(a, b);
    }

    public static long[] cloneArray(long[] n) {
        return n.clone();
    }

    public static void write(BufferedWriter writer, String s) throws IOException {
        writer.write(s);
    }

    public static void print(BufferedWriter writer) throws IOException {
        writer.flush();
    }

    public static String readLine(BufferedReader reader) throws IOException {
        return reader.readLine();
    }

    public static long readInt(BufferedReader reader) throws IOException {
        return Long.parseLong(reader.readLine());
    }

    public static double readFloat(BufferedReader reader) throws IOException {
        return Double.parseDouble(reader.readLine());
    }

    public static char[] readRunes(BufferedReader reader) throws IOException {
        return reader.readLine().toCharArray();
    }

    public static String readString(BufferedReader reader) throws IOException {
        return reader.readLine();
    }

    public static String[] readStrings(BufferedReader reader) throws IOException {
        return reader.readLine().split(" ");
    }

    public static long s2i(String s) {
        return Long.parseLong(s);
    }

    public static String i2s(long i) {
        return Long.toString(i);
    }

    public static double s2f(String s) {
        return Double.parseDouble(s);
    }

    public static long abs(long i) {
        return Math.abs(i);
    }

    public static long max(long... a) {
        return Arrays.stream(a).max().orElse(Long.MIN_VALUE);
    }

    public static long min(long... a) {
        return Arrays.stream(a).min().orElse(Long.MAX_VALUE);
    }

    public static long sum(long[] i) {
        return Arrays.stream(i).sum();
    }

    public static String[] split(String s) {
        return s.split("\\s+");
    }

    public static long[] strArrayToIntArray(String[] strs) {
        return Arrays.stream(strs).mapToLong(Long::parseLong).toArray();
    }

    public static String[] intArrayToStrArray(long[] nums) {
        return Arrays.stream(nums).mapToObj(Long::toString).toArray(String[]::new);
    }

    public static String arrayToString(String[] strs) {
        return String.join(" ", strs);
    }

    public static long[] reverse(long[] res) {
        for (int i = 0, j = res.length - 1; i < j; i++, j--) {
            long temp = res[i];
            res[i] = res[j];
            res[j] = temp;
        }
        return res;
    }

    public static String[] reverseStr(String[] res) {
        for (int i = 0, j = res.length - 1; i < j; i++, j--) {
            String temp = res[i];
            res[i] = res[j];
            res[j] = temp;
        }
        return res;
    }
}
