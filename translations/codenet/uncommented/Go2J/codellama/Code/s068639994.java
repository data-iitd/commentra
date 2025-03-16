
import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] ls = new int[n];
        int[] lsRev = new int[n];
        for (int i = 0; i < n; i++) {
            ls[i] = scanner.nextInt();
            lsRev[i] = ls[i];
        }
        Arrays.sort(ls);
        Arrays.sort(lsRev);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int p = Math.min(ls[i], ls[j]);
                int q = Math.max(ls[i], ls[j]);
                int x = q - p;
                int y = q + p;
                int l = Arrays.binarySearch(ls, x);
                int r = n - Arrays.binarySearch(lsRev, y);
                int sum = r - l;
                if (i >= l && i <= r) {
                    sum--;
                }
                if (j >= l && j <= r) {
                    sum--;
                }
                sum = Math.max(0, sum);
                ans += sum;
            }
        }
        ans /= 3;
        System.out.println(ans);
    }
}

