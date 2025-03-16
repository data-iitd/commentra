public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int r = scanner.nextInt();
        int g = scanner.nextInt();
        int b = scanner.nextInt();
        int n = scanner.nextInt();
        int ans = 0;

        for (int i = 0; i <= n / r; ++i) {
            for (int j = 0; j <= n / g; ++j) {
                int num = n - r * i - g * j;
                if (num >= 0 && num % b == 0) {
                    ++ans;
                }
            }
        }

        System.out.println(ans);
    }
}
