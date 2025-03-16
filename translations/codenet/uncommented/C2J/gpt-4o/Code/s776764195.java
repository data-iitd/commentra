import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CountingSortExample {
    private static final int MAX_N = 2000001;
    private static final int MAX_Ai = 10001;
    private static final int STR_SIZE = 10000010;

    private static int[] A = new int[MAX_N];
    private static int[] B = new int[MAX_N];
    private static StringBuilder str = new StringBuilder(STR_SIZE);
    private static int p = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String input = reader.readLine();
        str.append(input);

        int n = getNum();
        for (int i = 1; i <= n; ++i) {
            A[i] = getNum();
        }

        CountingSort(A, B, MAX_Ai, n);

        StringBuilder output = new StringBuilder();
        for (int i = 1; i < n; ++i) {
            putNum(B[i], output);
            output.append(' ');
        }
        putNum(B[n], output);

        System.out.println(output.toString());
    }

    private static int getNum() {
        int n = 0;
        while (p < str.length() && str.charAt(p) >= '0' && str.charAt(p) <= '9') {
            n = n * 10 + (str.charAt(p) - '0');
            p++;
        }
        p++; // Skip the space or newline
        return n;
    }

    private static void putNum(int n, StringBuilder output) {
        if (n < 10) {
            output.append((char) ('0' + n));
            return;
        }
        int d = n / 10;
        if (d > 0) putNum(d, output);
        output.append((char) ('0' + (n - (d * 10))));
    }

    private static void CountingSort(int[] A, int[] B, int k, int len) {
        int[] C = new int[MAX_Ai];
        for (int j = 1; j <= len; ++j) {
            C[A[j]]++;
        }
        for (int i = 1; i <= k; ++i) {
            C[i] += C[i - 1];
        }
        for (int j = len; j > 0; --j) {
            B[C[A[j]]] = A[j];
            C[A[j]]--;
        }
    }
}

// <END-OF-CODE>
