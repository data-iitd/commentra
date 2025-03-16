
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final StringBuilder sb = new StringBuilder();

    private static int N;
    private static int[] A;
    private static int[] B;
    private static int[] C;
    private static int[] D;
    private static int[] E;
    private static int[] F;

    public static void main(String[] args) throws IOException {
        N = readInt();
        A = readIntArray(N);
        B = readIntArray(N);
        C = readIntArray(N);
        D = readIntArray(N);
        E = readIntArray(N);
        F = readIntArray(N);

        int[] evens = new int[N];
        int[] odds = new int[N];

        int cur = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] == 1) {
                cur++;
            } else {
                evens[i] = cur;
                cur = 0;
            }
        }
        evens[N - 1] = cur;

        cur = 0;
        for (int i = 0; i < N; i++) {
            if (B[i] == 1) {
                cur++;
            } else {
                odds[i] = cur;
                cur = 0;
            }
        }
        odds[N - 1] = cur;

        boolean[][] dpx = new boolean[N + 1][20001];
        boolean[][] dpy = new boolean[N + 1][20001];

        dpx[0][10000] = true;
        dpy[0][10000] = true;

        for (int i = 0; i < N; i++) {
            for (int j = 2000; j <= 18000; j++) {
                if (j + evens[i] <= 18000) {
                    dpx[i + 1][j + evens[i]] = dpx[i + 1][j + evens[i]] || dpx[i][j];
                }
                if (j - evens[i] >= 2000 && i != 0) {
                    dpx[i + 1][j - evens[i]] = dpx[i + 1][j - evens[i]] || dpx[i][j];
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 2000; j <= 18000; j++) {
                if (j + odds[i] <= 18000) {
                    dpy[i + 1][j + odds[i]] = dpy[i + 1][j + odds[i]] || dpy[i][j];
                }
                if (j - odds[i] >= 2000) {
                    dpy[i + 1][j - odds[i]] = dpy[i + 1][j - odds[i]] || dpy[i][j];
                }
            }
        }

        if (dpx[N][C[0] + 10000] && dpy[N][D[0] + 10000]) {
            sb.append("Yes\n");
        } else {
            sb.append("No\n");
        }

        System.out.println(sb);
    }

    private static int readInt() throws IOException {
        return Integer.parseInt(br.readLine());
    }

    private static int[] readIntArray(int N) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        return A;
    }

    private static long readLong() throws IOException {
        return Long.parseLong(br.readLine());
    }

    private static long[] readLongArray(int N) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = Long.parseLong(st.nextToken());
        }
        return A;
    }

    private static double readDouble() throws IOException {
        return Double.parseDouble(br.readLine());
    }

    private static double[] readDoubleArray(int N) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        double[] A = new double[N];
        for (int i = 0; i < N; i++) {
            A[i] = Double.parseDouble(st.nextToken());
        }
        return A;
    }

    private static String readLine() throws IOException {
        return br.readLine();
    }

    private static String readString() throws IOException {
        return br.readLine();
    }

    private static int[][] readIntMatrix(int R, int C) throws IOException {
        int[][] A = new int[R][C];
        for (int i = 0; i < R; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                A[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        return A;
    }

    private static long[][] readLongMatrix(int R, int C) throws IOException {
        long[][] A = new long[R][C];
        for (int i = 0; i < R; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                A[i][j] = Long.parseLong(st.nextToken());
            }
        }
        return A;
    }

    private static double[][] readDoubleMatrix(int R, int C) throws IOException {
        double[][] A = new double[R][C];
        for (int i = 0; i < R; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                A[i][j] = Double.parseDouble(st.nextToken());
            }
        }
        return A;
    }

    private static char[] readCharArray(int N) throws IOException {
        char[] A = new char[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = st.nextToken().charAt(0);
        }
        return A;
    }

    private static String[] readStringArray(int N) throws IOException {
        String[] A = new String[N];
        for (int i = 0; i < N; i++) {
            A[i] = br.readLine();
        }
        return A;
    }

    private static int[] readIntArray(int N) throws IOException {
        int[] A = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        return A;
    }

    private static long[] readLongArray(int N) throws IOException {
        long[] A = new long[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Long.parseLong(st.nextToken());
        }
        return A;
    }

    private static int[] readIntArray(int N, String S) throws IOException {
        int[] A = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        return A;
    }

    private static long[] readLongArray(int N, String S) throws IOException {
        long[] A = new long[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Long.parseLong(st.nextToken());
        }
        return A;
    }

    private static int[][] readIntMatrix(int R, int C, String S) throws IOException {
        int[][] A = new int[R][C];
        for (int i = 0; i < R; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                A[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        return A;
    }

    private static long[][] readLongMatrix(int R, int C, String S) throws IOException {
        long[][] A = new long[R][C];
        for (int i = 0; i < R; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                A[i][j] = Long.parseLong(st.nextToken());
            }
        }
        return A;
    }

    private static int[][] readIntMatrix(int R, int C) throws IOException {
        int[][] A = new int[R][C];
        for (int i = 0; i < R; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                A[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        return A;
    }

    private static long[][] readLongMatrix(int R, int C) throws IOException {
        long[][] A = new long[R][C];
        for (int i = 0; i < R; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < C; j++) {
                A[i][j] = Long.parseLong(st.nextToken());
            }
        }
        return A;
    }

    private static int[] readIntArray(String S) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] A = new int[st.countTokens()];
        for (int i = 0; i < A.length; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        return A;
    }

    private static long[] readLongArray(String S) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        long[] A = new long[st.countTokens()];
        for (int i = 0; i < A.length; i++) {
            A[i] = Long.parseLong(st.nextToken());
        }
        return A;
    }

    private static int[] readIntArray(int N, String S) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        return A;
    }

    private static long[] readLongArray(int N, String S) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = Long.parseLong(st.nextToken());
        }
        return A;
    }

    private static int[] readIntArray(int N, int M, String S) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        return A;
    }

    private static long[] readLongArray(int N, int M, String S) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
      