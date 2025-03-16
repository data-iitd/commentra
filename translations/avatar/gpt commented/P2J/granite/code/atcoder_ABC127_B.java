
import java.util.Scanner;

public class atcoder_ABC127_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double r = scanner.nextDouble();
        double D = scanner.nextDouble();
        double x = scanner.nextDouble();

        for (int i = 2; i <= 11; i++) {
            double result = Math.pow(r, i - 1) * (x + D / (1 - r)) - D / (1 - r);
            System.out.println((int) result);
        }
    }
}
