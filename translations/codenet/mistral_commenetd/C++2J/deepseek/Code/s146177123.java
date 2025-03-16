import java.util.*;
import java.io.*;

public class SegmentTree {
    static boolean[][] seg = {
        {false, true, true, true, true, true, true},
        {false, false, false, false, true, true, false},
        {true, false, true, true, false, true, true},
        {true, false, false, true, true, true, true},
        {true, true, false, false, true, true, false},
        {true, true, false, true, true, false, true},
        {true, true, true, true, true, false, true},
        {false, true, false, false, true, true, true},
        {true, true, true, true, true, true, true},
        {true, true, false, true, true, true, true}
    };

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            if (n == -1) break;
            boolean[] st = new boolean[7];
            for (int i = 0; i < n; i++) {
                int t = scanner.nextInt();
                char[] ans = new char[8];
                Arrays.fill(ans, '0');
                for (int j = 0; j < 7; j++) {
                    ans[j] = (st[j] ^ seg[t][j]) ? '1' : '0';
                    st[j] = seg[t][j];
                }
                System.out.println(new String(ans));
            }
        }
        scanner.close();
    }
}
