public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        int ans = 0;

        // gu gu
        ans += n * (n - 1) / 2;

        // kiki
        ans += m * (m - 1) / 2;

        System.out.println(ans);
    }
}
