public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        long[] s = new long[n + 1];
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + a[i];
        }

        java.util.Arrays.sort(s);

        int ans = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == s[i + 1]) {
                count++;
            } else if (count > 0) {
                ans += combination(count + 1, 2);
                count = 0;
            }
        }
        if (count > 0) {
            ans += combination(count + 1, 2);
        }

        System.out.println(ans);
    }

    public static int combination(int n, int r) {
        int c = 1;
        for (int i = 1; i <= r; i++) {
            c = c * (n - i + 1) / i;
        }
        return c;
    }
}
