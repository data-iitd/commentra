public class Main {
    public static void main(String[] args) {
        int N, D; // N, Dは1以上20以下の整数
        int ans, rem;

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        N = scanner.nextInt();
        D = scanner.nextInt();

        ans = N / (D * 2 + 1);
        rem = N % (D * 2 + 1);

        if (rem != 0) {
            ans = ans + 1;
        }

        System.out.println(ans);
    }
}
