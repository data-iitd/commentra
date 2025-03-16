
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        new Main().run();
    }

    public void run() {
        int n;
        int[] A = new int[MAX_N];
        int[] B = new int[MAX_N];
        String str = new String(new char[STR_SIZE]);
        StringTokenizer st = new StringTokenizer(new BufferedReader(new InputStreamReader(System.in)).readLine());
        n = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= n; ++i) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        CountingSort(A, B, MAX_Ai, n);
        for (int i = 1; i <= n; ++i) {
            System.out.print(B[i]);
            if (i < n) System.out.print(' ');
        }
        System.out.println();
    }

    public void CountingSort(int[] A, int[] B, int k, int len) {
        int[] C = new int[MAX_Ai];
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

