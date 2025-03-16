import java.util.Scanner;
import java.lang.Math;

public class ClockAngle {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a, b, h, m;
        a = scanner.nextInt();
        b = scanner.nextInt();
        h = scanner.nextInt();
        m = scanner.nextInt();

        double C = Math.abs(360.0 / 60.0 * m - 360.0 / 12.0 * h - 360.0 / 12.0 / 60.0 * m);
        if (C > 180) {
            C = 360 - C;
        }

        double cosC = Math.cos(Math.toRadians(C));
        System.out.println(Math.sqrt(a * a + b * b - 2 * a * b * cosC));
    }
}
