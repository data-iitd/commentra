
import java.util.Arrays;
import java.util.Scanner;

public class s443186486{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int[] s = new int[n + 1];
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + a[i];
        }
        Arrays.sort(s);
        int ans = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == s[i + 1]) {
                count++;
            } else {
                if (count > 0) {
                    ans += combi(count + 1, 2);
                    count = 0;
                }
            }
        }
        if (count > 0) {
            ans += combi(count + 1, 2);
        }
        System.out.println(ans);
    }

    // Helper function to calculate the number of combinations of 'n' elements taken 'r' at a time
    public static int combi(int n, int r) {
        int c = 1;
        for (int i = 1; i <= r; i++) {
            c = c * (n - i + 1) / i;
        }
        return c;
    }
}

