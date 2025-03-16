import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] lst = new int[N];
        for (int i = 0; i < N; i++) {
            lst[i] = sc.nextInt();
        }
        int[] lst_p = new int[N];
        int[] lst_m = new int[N];
        int p = 0;
        int m = 0;
        int x = 0;
        int y = N - 1;
        int lastx = N - 1;
        int lasty = N - 1;
        for (int i = 0; i < N; i++) {
            if (lst[i] == 0) {
                K--;
            }
            if (lst[i] > 0) {
                lst_p[i] = lst[i];
            } else if (lst[i] < 0) {
                lst_m[i] = lst[i];
            }
        }
        for (int j = 0; j <= K; j++) {
            if (j > lastx || K - j > lasty) {
                continue;
            }
            if (j == 0) {
                p = 0;
            } else {
                p = lst_p[j - 1];
            }
            if (K - j == 0) {
                m = 0;
            } else {
                m = lst_m[lasty - (K - j)];
            }
            int ans = Math.min(ans, 2 * p + Math.abs(m), p + 2 * Math.abs(m));
        }
        System.out.println(ans);
    }
}

