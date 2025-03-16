import java.util.Scanner;

public class Main {
    static int[] data = new int[111112]; // Adjusted size to accommodate 0-index
    static int[] seq = new int[222223]; // Adjusted size to accommodate 0-index

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, k, t, p, ret;

        while (true) {
            n = scanner.nextInt();
            k = scanner.nextInt();
            if (n == 0 && k == 0) break;

            // Reset data and seq arrays
            for (int i = 0; i < data.length; i++) {
                data[i] = 0;
            }
            for (int i = 0; i < seq.length; i++) {
                seq[i] = 0;
            }

            for (int i = 0; i < k; i++) {
                t = scanner.nextInt();
                data[t]++;
            }

            p = 0;
            for (int i = 1; i <= n; i++) {
                if (data[i] > 0) {
                    seq[p]++;
                } else {
                    p += 2;
                }
            }
            p++;

            ret = 0; // Initialize ret for each case
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

        scanner.close();
    }

    static int max(int a, int b) {
        return (a > b) ? a : b;
    }
}
// <END-OF-CODE>
