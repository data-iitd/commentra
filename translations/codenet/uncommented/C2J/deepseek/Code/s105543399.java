public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        long n = scanner.nextLong();
        long m = 100000000;
        long M = -100000000;
        long c = 0;

        for (long i = 1; i <= n; i++) {
            long a = scanner.nextLong();
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
