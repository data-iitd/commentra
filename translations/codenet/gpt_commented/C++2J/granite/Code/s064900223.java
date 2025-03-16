
import java.util.Scanner;

public class s064900223{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = scanner.nextInt();
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (p[i] == i + 1) {
                p[i + 1] = p[i];
                ans += 1;
            }
        }
        if (p[n - 1] == n) {
            ans += 1;
        }
        System.out.println(ans);
    }
}
