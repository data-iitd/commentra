import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] a = new int[m];
        int sum = 0;
        for (int i = 0; i < m; i++) {
            a[i] = scanner.nextInt();
            sum += a[i];
            if (sum > n) {
                System.out.println("-1");
                return;
            }
        }
        System.out.println(n - sum);
    }
}
