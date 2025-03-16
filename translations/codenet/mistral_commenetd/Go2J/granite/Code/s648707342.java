

import java.util.Arrays;
import java.util.Scanner;

public class s648707342{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] arms = new int[n][2];
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int l = scanner.nextInt();
            arms[i][0] = x - l;
            arms[i][1] = x + l;
        }
        Arrays.sort(arms, (a, b) -> a[1] - b[1]);
        int ans = 1;
        int r = arms[0][1];
        for (int i = 1; i < n; i++) {
            if (arms[i][0] >= r) {
                ans++;
                r = arms[i][1];
            }
        }
        System.out.println(ans);
    }
}

