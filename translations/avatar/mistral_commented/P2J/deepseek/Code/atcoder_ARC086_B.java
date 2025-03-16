import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    static StringTokenizer st;

    static final int mod = (int) (1e9 + 7);

    static int I() throws IOException {
        return Integer.parseInt(br.readLine().trim());
    }

    static int[] III() throws IOException {
        String[] line = br.readLine().trim().split(" ");
        int[] out = new int[line.length];
        for (int i = 0; i < line.length; i++) out[i] = Integer.parseInt(line[i]);
        return out;
    }

    static void Line(int N, int num) throws IOException {
        if (N <= 0) {
            System.out.println("[[[]] * " + num + "]");
        } else if (num == 1) {
            for (int i = 0; i < N; i++) {
                int[] line = III();
                for (int j = 0; j < line.length; j++) {
                    out.print(line[j] + " ");
                }
                out.println();
            }
        } else {
            List<int[]> readAll = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                readAll.add(III());
            }
            for (int j = 0; j < num; j++) {
                for (int i = 0; i < N; i++) {
                    out.print(readAll.get(i)[j] + " ");
                }
                out.println();
            }
        }
    }

    public static void main(String[] args) throws IOException {
        int N = I();
        int[] a = III();
        int maxVal = 0;
        int maxSign = 0;
        int maxIndex = -1;

        for (int i = 0; i < a.length; i++) {
            if (Math.abs(a[i]) > maxVal) {
                maxVal = Math.abs(a[i]);
                maxSign = signum(a[i]);
                maxIndex = i;
            }
        }

        if (maxSign == 0) {
            out.println(0);
        } else if (maxSign == 1) {
            out.println(2 * N - 1);
            out.println((maxIndex + 1) + " " + 1);
            for (int i = 1; i < N; i++) {
                out.println((i + 1) + " " + (i + 2));
            }
        } else {
            out.println(2 * N - 1);
            out.println((maxIndex + 1) + " " + 1);
            for (int i = N - 1; i > 0; i--) {
                out.println((i + 1) + " " + i);
            }
        }
        out.flush();
    }

    static int signum(int a) {
        return a == 0 ? 0 : (a > 0 ? 1 : -1);
    }
}
