public class Main {
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        int[] P = new int[N];
        for (int i = 0; i < N; i++) {
            P[i] = Integer.parseInt(args[i + 1]);
        }
        editorial(N, P);
    }
    public static void editorial(int N, int[] P) {
        if (N == 1) {
            System.out.println(0);
            return;
        }
        int[] a = new int[N + 1];
        for (int i = 0; i < N; i++) {
            a[P[i]] = i;
        }
        int tmp = 1;
        int max_len = 1;
        for (int i = 1; i < N; i++) {
            if (a[i] < a[i + 1]) {
                tmp += 1;
                max_len = Math.max(max_len, tmp);
            } else {
                tmp = 1;
            }
        }
        int ans = N - max_len;
        System.out.println(ans);
    }
    public static void WA(int N, int[] P) {
        int tmp = 0;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (i == 0 || P[i - 1] + 1 == P[i]) {
                tmp += 1;
            } else {
                ans = Math.max(ans, tmp);
                tmp = 1;
            }
        }
        System.out.println(N - ans);
    }
}
