import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt();
        int n = scanner.nextInt();
        int w = scanner.nextInt();

        if (1 <= k && k <= 1000 && 1 <= n && n <= 1000 && 1 <= w && w <= 1000) {
            int total = 0;
            for (int i = 1; i <= w; i++) {
                total += i * k;
            }

            if (total > n) {
                System.out.println(total - n);
            } else {
                System.out.println(0);
            }
        }
