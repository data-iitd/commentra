public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        int nx = 0, ny = 0, nt = 0;
        for (int i = 0; i < N; i++) {
            int t = scanner.nextInt();
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            int tmp = t - nt - (Math.abs(x - nx) + Math.abs(y - ny));
            if (tmp < 0 || tmp % 2 != 0) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}
