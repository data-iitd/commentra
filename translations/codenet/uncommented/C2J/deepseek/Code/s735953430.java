public class Main {
    public static void main(String[] args) {
        int i_min, min;
        int i, j, k;
        int X, N;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        X = scanner.nextInt();
        N = scanner.nextInt();
        if (N == 0) {
            System.out.println(X);
            return;
        }

        int[] plus = new int[256];
        int[] minus = new int[256];
        for (i = 0; i < 256; i++) {
            plus[i] = i;
            minus[i] = -1 * i;
        }
        for (i = 0; i < N; i++) {
            j = scanner.nextInt();
            plus[j] = 0;
        }

        i_min = 0;
        min = 1000;
        for (i = 255; i >= 0; i--) {
            if (plus[i] == 0 && i > 0) {
                continue;
            }
            k = X - plus[i];
            if (k < 0) {
                k *= -1;
            }
            if (k <= min) {
                min = k;
                i_min = i;
            }
        }

        System.out.println(i_min);
    }
}
