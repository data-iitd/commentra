import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            int a, b, n;
            if (!scanner.hasNextInt()) break;
            a = scanner.nextInt();
            b = scanner.nextInt();
            n = scanner.nextInt();
            
            a -= a / b * b;
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                a *= 10;
                int j;
                for (j = 9; j >= 0; j--) {
                    if (b * j <= a) break;
                }
                a -= b * j;
                sum += j;
            }
            System.out.println(sum);
        }
        scanner.close();
    }
}
// <END-OF-CODE>
