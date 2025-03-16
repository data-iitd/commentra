import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        if (n == 0) {
            System.out.println("0");
            return;
        }

        StringBuilder s = new StringBuilder();

        while (n != 0) {
            if (n % 2 == 0) {
                s.append('0');
            } else {
                s.append('1');
            }

            n -= Math.abs(n % 2);
            n /= -2;
        }

        System.out.println(s.reverse().toString());
    }
}

