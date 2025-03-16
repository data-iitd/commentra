import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int maxn = 200000 + 10;
        int[] maps = new int[maxn];
        int[] num = new int[maxn];

        while (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            for (int i = 1; i <= n; i++) {
                maps[i] = scanner.nextInt();
                num[i] = maps[i];
            }
            Arrays.sort(maps, 1, n + 1);
            int m = n / 2;
            for (int i = 1; i <= n; i++) {
                if (num[i] <= maps[m]) {
                    System.out.println(maps[m + 1]);
                } else {
                    System.out.println(maps[m]);
                }
            }
        }
        scanner.close();
    }
}
// <END-OF-CODE>
