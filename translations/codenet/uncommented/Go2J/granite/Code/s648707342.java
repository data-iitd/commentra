
import java.util.Arrays;
import java.util.Scanner;

public class s648707342{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] as = new int[n][2];
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int l = scanner.nextInt();
            as[i][0] = x - l;
            as[i][1] = x + l;
        }
        Arrays.sort(as, (a, b) -> Integer.compare(a[1], b[1]));

        int ans = 1;
        int r = as[0][1];
        for (int i = 1; i < n; i++) {
            if (as[i][0] >= r) {
                ans++;
                r = as[i][1];
            }
        }
        System.out.println(ans);
    }
}

