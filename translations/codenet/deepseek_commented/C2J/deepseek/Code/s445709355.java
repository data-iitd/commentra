public class Main {
    static int[] f1 = new int[100];
    static int[] f2 = new int[100];

    static int in() {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        return scanner.nextInt();
    }

    static void calc(int n) {
        int k = n % 10;
        while (n >= 10) n /= 10;
        ++f1[10 * k + n];
        ++f2[n * 10 + k];
    }

    public static void main(String[] args) {
        int i, N, ans;
        N = in();
        while (N > 0) calc(N--);

        ans = 0;
        for (i = 0; i < 100; ++i) ans += f1[i] * f2[i];
        System.out.println(ans);
    }
}
