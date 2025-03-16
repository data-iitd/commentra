

import java.util.Scanner;

public class atcoder_ABC168_C{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int h = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.close();

        double C = Math.abs(360.0 / 60 * m - 360.0 / 12 * h - 360.0 / 12 / 60 * m);
        if (C > 180) {
            C = 360 - C;
        }
        double cosC = Math.cos(Math.toRadians(C));
        double length = Math.sqrt(a * a + b * b - 2 * a * b * cosC);
        System.out.println(length);
    }
}
// Printing the length of the line segment connecting the tips of the hour and minute hands using the Law of Cosines



Translate the above Python code to JavaScript and end with comment "