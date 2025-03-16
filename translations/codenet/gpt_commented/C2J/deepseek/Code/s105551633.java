public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        long n = scanner.nextLong();
        int min = digit(n);
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                long a = i;
                long b = n / i;
                min = Math.min(min, Math.max(digit(a), digit(b)));
            }
        }
        System.out.println(min);
    }

    public static int digit(long n) {
        int res = 0;
        while (n > 0) {
            res++;
            n /= 10;
        }
        return res;
    }
}
