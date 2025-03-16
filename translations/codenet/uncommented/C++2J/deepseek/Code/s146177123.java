import java.util.*;

public class DigitDisplay {
    static boolean[][] seg = {
        {0, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 1, 0, 1, 1},
        {1, 0, 0, 1, 1, 1, 1},
        {1, 1, 0, 0, 1, 1, 0},
        {1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 0, 1},
        {0, 1, 0, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 1, 1}
    };

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            if (n == 0) break;
            boolean[] st = new boolean[7];
            for (int i = 0; i < n; i++) {
                int t = scanner.nextInt();
                char[] ans = new char[7];
                for (int j = 0; j < 7; j++) {
                    ans[j] = st[j] ^ seg[t][j] ? '1' : '0';
                    st[j] = seg[t][j];
                }
                System.out.println(new String(ans));
            }
        }
        scanner.close();
    }
}
