import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int s = 0;
        int remainder = 0;

        while (a > 0 || remainder >= b) {
            a += remainder / b;
            remainder %= b;
            s += a;
            remainder += a % b;
            a /= b;
        }

        System.out.println(s);
    }
}
