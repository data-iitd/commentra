public class Main {
    public static void main(String[] args) {
        int l, r, d;
        int ans = 0;

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        l = scanner.nextInt();
        r = scanner.nextInt();
        d = scanner.nextInt();

        for (int i = l; i <= r; i++) {
            if (i % d == 0) ans++;
        }

        System.out.println(ans);
    }
}
