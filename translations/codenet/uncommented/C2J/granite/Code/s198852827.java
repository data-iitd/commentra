
import java.util.Scanner;

public class s198852827{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int t = 0, x = 0, y = 0, nx = 0, ny = 0, nt = 0;
        for (int i = 0; i < N; i++) {
            nt = scanner.nextInt();
            nx = scanner.nextInt();
            ny = scanner.nextInt();
            int tmp = nt - t - Math.abs(nx - x) - Math.abs(ny - y);
            if (tmp < 0 || tmp % 2!= 0) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}
