
import java.util.Scanner;

public class s225883945{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        a[0] = 0;
        int sum = k;
        int ans = 1;
        while (sum < n) {
            sum = sum - 1 + k;
            ans++;
        }
        System.out.println(ans);
    }
}
