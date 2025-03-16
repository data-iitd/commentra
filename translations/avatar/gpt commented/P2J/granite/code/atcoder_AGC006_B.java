
import java.util.Scanner;

public class atcoder_AGC006_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int X = scanner.nextInt();
        int[] x = new int[N];
        for (int i = 0; i < N; i++) {
            x[i] = i + 1;
        }
        int result = calc(x, X);
        if (X == 1 || X == N * 2 - 1) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
            if (X == N * 2 - 2) {
                for (int i = N - 1; i <= X + 1; i++) {
                    System.out.println(i);
                }
            } else {
                int[] y = new int[N - 3];
                for (int i = 0; i < N - 3; i++) {
                    y[i] = i + 1;
                }
                y[N - 4] = X + 2;
                y[N - 3] = X - 1;
                y[N - 2] = X;
                y[N - 1] = X + 1;
                for (int i = 0; i < N - 3; i++) {
                    System.out.println(y[i]);
                }
            }
        }
    }

    public static int calc(int[] x, int X) {
        int[] y = new int[x.length];
        for (int i = 0; i < x.length; i++) {
            y[i] = x[i];
        }
        while (y.length > 1) {
            int[] z = new int[y.length - 2];
            for (int i = 0; i < z.length; i++) {
                z[i] = Math.max(y[i], Math.max(y[i + 1], y[i + 2]));
            }
            y = z;
        }
        if (y[0] == 2) {
            int[] z = new int[x.length];
            for (int i = 0; i < z.length; i++) {
                z[i] = x[i];
            }
            while (z.length > 1) {
                int[] w = new int[z.length - 2];
                for (int i = 0; i < w.length; i++) {
                    w[i] = Math.max(z[i], Math.max(z[i + 1], z[i + 2]));
                }
                z = w;
            }
            System.out.println("=" + Arrays.toString(x));
        }
        return y[0];
    }
}
