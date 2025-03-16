
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        new Main().run();
    }

    public void run() {
        try {
            BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer s = new StringTokenizer(r.readLine());
            int n = Integer.parseInt(s.nextToken());
            int[] A = new int[n + 1];
            int[] B = new int[n + 1];
            StringTokenizer t = new StringTokenizer(r.readLine());
            for (int i = 1; i <= n; ++i) {
                A[i] = Integer.parseInt(t.nextToken());
            }
            CountingSort(A, B, 10001, n);
            for (int i = 1; i <= n; ++i) {
                System.out.print(B[i] + " ");
            }
            System.out.println();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void CountingSort(int[] A, int[] B, int k, int len) {
        int[] C = new int[k];
        int i, j;
        for (j = 1; j <= len; ++j) {
            ++C[A[j]];
        }
        for (i = 1; i <= k; ++i) {
            C[i] += C[i - 1];
        }
        for (j = len; j > 0; --j) {
            B[C[A[j]]] = A[j];
            --C[A[j]];
        }
    }
}

