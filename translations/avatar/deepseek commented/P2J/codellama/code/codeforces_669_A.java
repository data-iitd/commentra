
import java.util.Scanner;

public class Fibonacci {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(fibonacci(n));
    }

    public static int fibonacci(int n) {
        if (n <= 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            int a = 0;
            int b = 1;
            for (int i = 2; i <= n; i++) {
                int temp = a;
                a = b;
                b = temp + b;
            }
            return b;
        }
    }
}
