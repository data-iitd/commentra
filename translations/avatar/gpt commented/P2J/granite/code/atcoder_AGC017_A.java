
import java.util.*;

public class atcoder_AGC017_A{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int P = sc.nextInt();
        int[] lis = new int[N];
        for (int i = 0; i < N; i++) {
            lis[i] = sc.nextInt();
        }
        int[] ls = new int[N];
        for (int i = 0; i < N; i++) {
            ls[i] = lis[i] % 2;
        }
        int one = 0;
        int zero = 0;
        for (int i = 0; i < N; i++) {
            if (ls[i] == 1) {
                one++;
            } else {
                zero++;
            }
        }
        long pattern_a = 0;
        long pattern_b = 0;
        for (int j = 0; j <= zero; j++) {
            pattern_b += combination(zero, j);
        }
        int time = 0;
        while (time <= one) {
            if (time % 2 == P) {
                pattern_a += combination(one, time);
            }
            time++;
        }
        System.out.println((int) (pattern_a * pattern_b));
    }

    public static long combination(int n, int r) {
        long a = 1;
        for (int i = 0; i < r; i++) {
            a *= (n - i);
        }
        for (int j = 0; j < r; j++) {
            a /= (j + 1);
        }
        return a;
    }
}
