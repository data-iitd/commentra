public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        int i = 1;
        int ans = 0;
        while (Math.pow(10, i) <= N) {
            ans += (int) (Math.pow(10, i)) - (int) (Math.pow(10, i - 1));
            i += 2;
        }
        ans += Math.max(0, N - (int) (Math.pow(10, i - 1)) + 1);
        System.out.println(ans);
    }
}
