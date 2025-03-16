public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int ans = 0;
        for (int i = 1; i * i < n; i++) {
            if (n % i == 0 && n % (n / i - 1) == i) {
                ans += n / i - 1;
            }
        }
        System.out.println(ans);
    }
}
