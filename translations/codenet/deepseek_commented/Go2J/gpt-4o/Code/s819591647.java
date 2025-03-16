import java.util.*;
import java.io.*;

public class ProblemB {
    private static final int constMod = (int) (1e9 + 7);
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static PrintWriter wr = new PrintWriter(System.out);

    // Utility function to read an integer from input
    private static int getInt() throws IOException {
        return Integer.parseInt(br.readLine().trim());
    }

    // Utility function to read a list of integers from input
    private static int[] getIntArray(int n) throws IOException {
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        return arr;
    }

    // Main logic of the program
    private static void solve() throws IOException {
        int n = getInt();
        int m = getInt();
        int[] a = getIntArray(n);

        int sum = 0;
        for (int v : a) {
            sum += v;
        }

        int count = 0;
        double rate = (double) sum / (4 * m);
        for (int v : a) {
            if (v >= rate) {
                count++;
            }
        }

        if (count >= m) {
            wr.println("Yes");
        } else {
            wr.println("No");
        }
    }

    public static void main(String[] args) throws IOException {
        solve();
        wr.flush();
    }
}

// <END-OF-CODE>
