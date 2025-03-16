public class ChainGame {
    public static int min(int a, int b) {
        if (a <= b) {
            return a;
        }
        return b;
    }

    public static int chain(int[] b, int n) {
        int[] a = new int[10000];
        for (int i = 0; i < n; i++) {
            a[i] = b[i];
        }

        for (int i = 0; i < n - 4; i++) {
            if (a[i] != 0 && a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] == a[i + 3]) {
                int count = 0;
                int color = a[i];

                for (int j = i; a[j] == color; j++) {
                    a[j] = 0;
                    count++;
                }

                for (int j = 0; i + j + count < n; j++) {
                    a[i + j] = a[i + j + count];
                    a[i + j + count] = 0;
                }

                i = 0;
            }
        }

        int count = 0;
        while (count < n && a[count] != 0) {
            count++;
        }

        if (count == 4 && a[0] == a[1] && a[0] == a[2] && a[0] == a[3]) {
            return 0;
        }

        return count;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        while (true) {
            int n = scanner.nextInt();
            if (n == 0) {
                break;
            }
            int[] a = new int[10000];
            int ans = n;

            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
            }

            for (int i = 0; i < n - 4; i++) {
                int[] count = new int[3];
                for (int j = i; j < i + 4; j++) {
                    if (a[j] - 1 >= 0) {
                        count[a[j] - 1]++;
                    }
                }

                int color = 0;
                for (int j = 0; j < 3; j++) {
                    if (count[j] >= 3) {
                        color = j + 1;
                        break;
                    }
                }

                if (color != 0) {
                    for (int j = i; j < i + 4; j++) {
                        int buf = a[j];
                        a[j] = color;
                        ans = min(ans, chain(a, n));
                        a[j] = buf;
                    }
                }
            }

            System.out.println(ans);
        }
    }
}
