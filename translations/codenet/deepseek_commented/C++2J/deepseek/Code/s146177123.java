import java.util.*;

public class SevenSegmentDisplay {
    // Array to represent the segments of the digits 0-9
    private static final boolean[][] seg = {
        {0, 1, 1, 1, 1, 1, 1}, // 0
        {0, 0, 0, 0, 1, 1, 0}, // 1
        {1, 0, 1, 1, 0, 1, 1}, // 2
        {1, 0, 0, 1, 1, 1, 1}, // 3
        {1, 1, 0, 0, 1, 1, 0}, // 4
        {1, 1, 0, 1, 1, 0, 1}, // 5
        {1, 1, 1, 1, 1, 0, 1}, // 6
        {0, 1, 0, 0, 1, 1, 1}, // 7
        {1, 1, 1, 1, 1, 1, 1}, // 8
        {1, 1, 0, 1, 1, 1, 1}  // 9
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
                Arrays.fill(ans, '0');
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
