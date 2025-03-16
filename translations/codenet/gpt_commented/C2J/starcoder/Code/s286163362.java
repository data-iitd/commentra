import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            if (n == 0 && k == 0) {
                break;
            }

            int[] data = new int[111111];
            int[] seq = new int[222222];

            for (int i = 0; i < k; i++) {
                int t = sc.nextInt();
                data[t]++;
            }

            int p = 0;
            for (int i = 1; i <= n; i++) {
                if (data[i] > 0) {
                    seq[p]++;
                } else {
                    p += 2;
                }
            }
            p++;

            int ret = 0;
            if (data[0] > 0) {
                for (int i = 0; i < p; i++) {
                    ret = Math.max(ret, seq[i] + seq[i + 2] + 1);
                }
            } else {
                for (int i = 0; i < p; i++) {
                    ret = Math.max(ret, seq[i]);
                }
            }

            System.out.println(ret);
        }
    }
}

