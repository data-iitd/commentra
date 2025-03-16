public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] x = new int[31];
        for (int i = 0; i < n; ++i) {
            int k = scanner.nextInt();
            for (int j = 0; j < k; ++j) {
                int a = scanner.nextInt();
                x[a]++;
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            if (x[i] == n) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
