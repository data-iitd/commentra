import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] p = new int[n];
        int ans = 0;

        for (int i = 0; i < n - 2; i++) {
            p[i] = scanner.nextInt();
            if (p[i] < p[i + 1] && p[i + 1] < p[i + 2]) {
                ans++;
            }
            if (p[i] > p[i + 1] && p[i + 1] > p[i + 2]) {
                ans++;
            }
        }

        System.out.println(ans);
    }
}
