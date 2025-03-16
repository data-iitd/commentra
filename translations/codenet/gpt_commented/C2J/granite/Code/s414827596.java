
import java.util.Scanner;

public class s414827596{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int c = scanner.nextInt();
            int d = scanner.nextInt();
            int e = scanner.nextInt();
            int f = scanner.nextInt();
            double x = (double) (c * e - f * b) / (a * e - d * b);
            double y = (double) (c * d - f * a) / (b * d - e * a);
            if (y <= 0 && y > -0.0005) y = 0;
            if (x <= 0 && x > -0.0005) x = 0;
            System.out.printf("%.3f %.3f%n", x, y);
        }
    }
}
// 