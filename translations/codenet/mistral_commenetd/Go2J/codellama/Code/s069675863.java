
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] evens;
    static int[] odds;

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int[] F = new int[N];
            for (int i = 0; i < N; i++) {
                F[i] = Integer.parseInt(st.nextToken());
            }
            int[] S = new int[M];
            for (int i = 0; i < M; i++) {
                S[i] = Integer.parseInt(st.nextToken());
            }

            evens = new int[N];
            odds = new int[N];
            for (int i = 0; i < N; i++) {
                if (i % 2 == 0) {
                    evens[i] = F[i];
                } else {
                    odds[i] = F[i];
                }
            }

            boolean[][] dpx = new boolean[N + 1][20000];
            boolean[][] dpy = new boolean[N + 1][20000];

            for (int i = 0; i < N; i++) {
                if (i % 2 == 0) {
                    updateDPX(i, evens[i], dpx);
                } else {
                    updateDPY(i, odds[i], dpy);
                }
            }

            if (dpx[N][S[0] + 10000] && dpy[N][S[1] + 10000]) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void updateDPX(int index, int val, boolean[][] dpx) {
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpx[index + 1][j + val] = dpx[index + 1][j + val] || dpx[index][j];
            }
            if (j - val >= 2000 && index != 0) {
                dpx[index + 1][j - val] = dpx[index + 1][j - val] || dpx[index][j];
            }
        }
    }

    private static void updateDPY(int index, int val, boolean[][] dpy) {
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpy[index + 1][j + val] = dpy[index + 1][j + val] || dpy[index][j];
            }
            if (j - val >= 2000) {
                dpy[index + 1][j - val] = dpy[index + 1][j - val] || dpy[index][j];
            }
        }
    }

}

