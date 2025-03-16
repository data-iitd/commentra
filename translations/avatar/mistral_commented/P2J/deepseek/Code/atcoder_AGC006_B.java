import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int X = scanner.nextInt();

        if (X == 1 || X == N * 2 - 1) {
            System.out.println("No");
            return;
        }

        System.out.println("Yes");

        int[] xs;
        if (X == N * 2 - 2) {
            xs = new int[N];
            for (int i = 0; i < N - 1; i++) {
                xs[i] = N - 1 + i + 1;
            }
            for (int i = 0; i < N - 1; i++) {
                xs[N - 1 + i + 1] = i + 1;
            }
        } else {
            int[] ys = new int[2 * N - 2];
            for (int i = 0; i < X - 1; i++) {
                ys[i] = i + 1;
            }
            for (int i = X + 2; i < N * 2; i++) {
                ys[i - 3] = i;
            }
            xs = new int[N];
            for (int i = 0; i < N - 3; i++) {
                xs[i] = ys[i];
            }
            xs[N - 3] = X + 2;
            xs[N - 2] = X - 1;
            xs[N - 1] = X;
            xs[N] = X + 1;
            for (int i = N - 2; i < 2 * N - 2; i++) {
                xs[i + 1] = ys[i];
            }
        }

        for (int x : xs) {
            System.out.println(x);
        }
    }
}
