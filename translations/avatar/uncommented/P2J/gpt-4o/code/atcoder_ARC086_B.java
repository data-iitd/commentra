import java.util.*;
import java.io.*;

public class Main {
    static final int MOD = 1000000007;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        int N = I();
        int[] a = III(N);
        int maxVal = 0;
        int maxSign = 0;
        int maxIndex = -1;

        for (int i = 0; i < N; i++) {
            int a0 = a[i];
            if (Math.abs(a0) > maxVal) {
                maxVal = Math.abs(a0);
                maxSign = mySign(a0);
                maxIndex = i;
            }
        }

        if (maxSign == 0) {
            System.out.println(0);
        } else {
            System.out.println(2 * N - 1);
            for (int i = 0; i < N; i++) {
                System.out.println((maxIndex + 1) + " " + (i + 1));
            }
            if (maxSign == 1) {
                for (int i = 0; i < N - 1; i++) {
                    System.out.println((i + 1) + " " + (i + 2));
                }
            } else {
                for (int i = N - 1; i > 0; i--) {
                    System.out.println((i + 1) + " " + i);
                }
            }
        }
    }

    static int I() throws IOException {
        return Integer.parseInt(next());
    }

    static int[] III(int N) throws IOException {
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = I();
        }
        return arr;
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    static int mySign(int x) {
        return (x > 0) ? 1 : (x < 0) ? -1 : 0;
    }
}
//<END-OF-CODE>
