public class Main {
    public static void main(String[] args) {
        long l, r, d;
        long ans = 0;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        l = scanner.nextLong();
        r = scanner.nextLong();
        d = scanner.nextLong();
        for (long i = l; i <= r; i++) {
            if (i % d == 0) ans++;
        }
        System.out.println(ans);
    }
}
