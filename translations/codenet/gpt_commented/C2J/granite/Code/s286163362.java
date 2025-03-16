
import java.util.Scanner;

public class s286163362{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] data = new int[1111111];
        int[] seq = new int[2222222];
        int n, k, t, i, p, ret = 0;

        while (true) {
            n = scanner.nextInt();
            k = scanner.nextInt();
            if (n == 0 && k == 0) {
                break;
            }
            for (i = 0; i < k; i++) {
                t = scanner.nextInt();
                data[t]++;
            }
            p = 0;
            for (i = 1; i <= n; i++) {
                if (data[i] > 0) {
                    seq[p]++;
                } else {
                    p += 2;
                }
            }
            p++;
            if (data[0] > 0) {
                for (i = 0; i < p; i++) {
                    ret = Math.max(ret, seq[i] + seq[i + 2] + 1);
                }
            } else {
                for (i = 0; i < p; i++) {
                    ret = Math.max(ret, seq[i]);
                }
            }
            System.out.println(ret);
        }
    }
}

// Translate the above Java code to Python and end with comment "