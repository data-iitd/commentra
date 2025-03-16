public class Main {
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        int i = 1;
        int ans = 0;
        while (10 ** i <= N) {
            ans += (10 ** i) - (10 ** (i - 1));
            i += 2;
        }
        ans += Math.max(0, N - 10 ** (i - 1) + 1);
        System.out.println(ans);
    }
}
