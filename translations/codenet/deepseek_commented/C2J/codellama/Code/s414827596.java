
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, b, c, d, e, f;
        double x, y;

        while (sc.hasNext()) {
            a = sc.nextInt();
            b = sc.nextInt();
            c = sc.nextInt();
            d = sc.nextInt();
            e = sc.nextInt();
            f = sc.nextInt();

            y = (double) (c * d - f * a) / (b * d - e * a);
            x = (double) (c * e - f * b) / (a * e - d * b);

            if (y <= 0 && y > -0.0005)
                y = 0;
            if (x <= 0 && x > -0.0005)
                x = 0;

            System.out.printf("%.3f %.3f\n", x, y);
        }
    }
}

