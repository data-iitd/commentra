
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int K = in.nextInt();
        int[] lst = new int[N];
        for (int i = 0; i < N; i++) {
            lst[i] = in.nextInt();
        }
        int[] lst_p = new int[N];
        int[] lst_m = new int[N];
        int p = 0;
        int m = 0;
        int x = 0;
        int y = N - 1;
        int lastx = 0;
        int lasty = N - 1;
        for (int i = 0; i < N; i++) {
            if (lst[i] == 0) {
                K--;
            }
            if (lst[i] > 0) {
                lst_p[lastx++] = lst[i];
            } else if (lst[i] < 0) {
                lst_m[lasty--] = lst[i];
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
            System.out.println(Math.min(Math.min(2 * p + Math.abs(m), p + 2 * Math.abs(m)), 1000000000));
        }
    }
}

