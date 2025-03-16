import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        StringBuilder s = new StringBuilder();

        if (n == 0) {
            System.out.println('0');
            return;
        }

        while (n != 0) {
            if (n % 2 == 0) {
                s.append('0');
            } else {
                s.append('1');
            }

            n -= Math.abs(n % 2);
            n /= -2;
        }

        s.reverse();
        System.out.println(s.toString());
    }
}
//<END-OF-CODE>
