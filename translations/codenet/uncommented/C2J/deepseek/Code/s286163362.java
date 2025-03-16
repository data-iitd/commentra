import java.util.Scanner;

public class Main {
    static int[] data = new int[111111];
    static int[] seq = new int[222222];

    public static int max(int a, int b) {
        return a > b ? a : b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int n = scanner.nextInt();
            int k = scanner.nextInt();
            if (n == 0 && k == 0) break;

            for (int i = 0; i < 111111; i++) {
                data[i] = 0;
            }
            for (int i = 0; i < 222222; i++) {
                seq[i] = 0;
            }

            for (int i = 0; i < k; i++) {
                int t = scanner.nextInt();
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
                    ret = max(ret, seq[i] + seq[i + 2] + 1);
                }
            } else {
                for (int i = 0; i < p; i++) {
                    ret = max(ret, seq[i]);
                }
            }

            System.out.println(ret);
        }
    }
}
