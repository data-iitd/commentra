

import java.util.Scanner;

public class s209996417{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double n = scanner.nextDouble();
        double k = scanner.nextDouble();

        double x = 0;
        while (true) {
            double under = Math.pow(k, x);
            double upper = Math.pow(k, x + 1);

            if (under <= n && n < upper) {
                System.out.println(x + 1);
                return;
            }
            x++;
        }
    }
}

