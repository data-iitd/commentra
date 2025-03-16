import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long N = scanner.nextLong();
        long K = scanner.nextLong();

        long[] A = new long[(int) (N + 1)];
        for (int i = 1; i <= N; i++) {
            A[i] = scanner.nextLong();
        }

        long cur = 1;
        long[] dic = new long[(int) (N + 1)];
        Arrays.fill(dic, -1);
        boolean flg = false;
        for (int i = 1; i <= K; i++) {
            if (dic[(int) cur] < 0 || flg) {
                dic[(int) cur] = i;
                cur = A[(int) cur];
            } else if (!flg) {
                long tmp = K - (dic[(int) cur] - 1);
                tmp %= i - dic[(int) cur];
                i = (int) (K - tmp);
                flg = true;
            }
        }

        System.out.println(cur);
    }
}
