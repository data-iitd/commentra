
import java.util.Scanner;

public class atcoder_ABC125_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double a = scanner.nextDouble();
        double b = scanner.nextDouble();
        double t = scanner.nextDouble();
        double time = a;
        int cookie = 0;
        while (time <= t + 0.5) {
            cookie += b;
            time += a;
        }
        System.out.println(cookie);
    }
}
