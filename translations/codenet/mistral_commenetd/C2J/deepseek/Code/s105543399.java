public class Main {
    public static void main(String[] args) {
        long n, a, m, M, c;
        m = 100000000;
        M = -100000000;
        c = 0;

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextLong();

        for (long i = 1; i <= n; i++) {
            a = scanner.nextLong();

            if (a > M) {
                M = a;
            }

            if (a < m) {
                m = a;
            }

            c = c + a;
        }

        System.out.println(m + " " + M + " " + c);
    }
}
