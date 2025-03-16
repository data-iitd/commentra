public class CountingSort {
    static final int MAX_N = 2000001;
    static final int MAX_Ai = 10001;
    static final int STR_SIZE = 10000010;

    static int[] A = new int[MAX_N];
    static int[] B = new int[MAX_N];
    static char[] str = new char[STR_SIZE];
    static char[] p = str;

    public static void main(String[] args) {
        java.io.BufferedReader reader = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
        try {
            int n = 0;
            int len = reader.read(str);
            for (int i = 0; i < len; i++) {
                if (str[i] >= '0' && str[i] <= '9') {
                    n = n * 10 + (int) (str[i] - '0');
                } else if (str[i] == '\n') {
                    break;
                }
            }
            for (int i = 0; i < n; i++) {
                A[i] = 0;
                while (str[p - str] >= '0' && str[p - str] <= '9') {
                    A[i] = A[i] * 10 + (int) (str[p - str] - '0');
                    p++;
                }
                p++;
            }
            CountingSort(A, B, MAX_Ai, n);
            p = str;
            for (int i = 0; i < n - 1; i++) {
                putNum(B[i]);
                System.out.print(" ");
            }
            putNum(B[n - 1]);
            System.out.println();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static int getNum() {
        int n = 0;
        while (p < str.length && str[p] >= '0' && str[p] <= '9') {
            n = n * 10 + (int) (str[p] - '0');
            p++;
        }
        p++;
        return n;
    }

    static void putNum(int n) {
        if (n < 10) {
            System.out.print((char) ('0' + n));
            return;
        }
        int d = n / 10;
        if (d > 0) putNum(d);
        System.out.print((char) ('0' + (n - (d * 10))));
    }

    static void CountingSort(int A[], int B[], int k, int len) {
        int[] C = new int[k + 1];
        for (int j = 0; j < len; j++) {
            C[A[j]]++;
        }
        for (int i = 1; i <= k; i++) {
            C[i] += C[i - 1];
        }
        for (int j = len - 1; j >= 0; j--) {
            B[C[A[j]] - 1] = A[j];
            C[A[j]]--;
        }
    }
}
