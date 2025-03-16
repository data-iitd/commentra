import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int nt = 0, nx = 0, ny = 0;

        for (int i = 0; i < N; i++) {
            int t = scanner.nextInt();
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            int tmp = t - nt - (Math.abs(x - nx) + Math.abs(y - ny));

            if (tmp < 0 || tmp % 2 != 0) {
                System.out.println("No");
                return;
            }

            nt = t;
            nx = x;
            ny = y;
        }
        System.out.println("Yes");
    }
}
// <END-OF-CODE>
