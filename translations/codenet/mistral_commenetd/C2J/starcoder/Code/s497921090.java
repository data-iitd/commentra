
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long a = 0, b = 0;
        for (int i = 1; i <= n; i++) {
            a += i;
        }
        b = (n * (n - 1)) / 2;
        System.out.println(b - a);
    }
}

