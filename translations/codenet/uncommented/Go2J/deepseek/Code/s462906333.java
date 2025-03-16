public class Main {
    public static void main(String[] args) {
        // Read input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        int inf = (int) 1e14;
        int ans = inf;

        for (int k = 0; k < n; k++) {
            int kans = 0;
            int[] v = new int[n];
            System.arraycopy(a, 0, v, 0, n);

            for (int i = 0; i < n; i++) {
                if (i - k < 0) {
                    v[i] = Math.min(v[i], a[n + i - k]);
                } else {
                    v[i] = Math.min(v[i], a[i - k]);
                }
                kans += v[i];
            }
            ans = Math.min(ans, kans + k * x);
        }

        System.out.println(ans);
    }
}
