
import java.util.Scanner;

public class codeforces_340_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        scanner.close();

        int lcm = lcm(x, y);
        int count = (b / lcm) - ((a - 1) / lcm);
        System.out.println(count);
    }

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
}

