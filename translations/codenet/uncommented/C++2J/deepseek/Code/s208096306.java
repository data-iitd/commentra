public class Main {
    public static int gcd(int a, int b) {
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        int r;
        while ((r = a % b) > 0) {
            a = b;
            b = r;
        }
        return b;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int ans = scanner.nextInt();

        for (int i = 1; i < n; ++i) {
            int a = scanner.nextInt();
            ans = gcd(ans, a);
        }

        System.out.println(ans);
    }
}
