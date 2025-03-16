
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            String x = sc.next();
            int[] s = new int[x.length()];
            for (int j = 0; j < x.length(); j++) {
                if (x.charAt(j) == 'O') {
                    s[j] = 0;
                } else {
                    s[j] = 1;
                }
            }
            int[] tot = new int[12];
            for (int j = 1; j <= 12; j++) {
                if (12 % j == 0) {
                    if (help(s, 12 / j, j)) {
                        tot[j - 1] = 1;
                    }
                }
            }
            System.out.print(Arrays.stream(tot).sum() + " ");
            for (int j = 0; j < 12; j++) {
                if (tot[j] == 1) {
                    System.out.print(j + 1 + " ");
                }
            }
            System.out.println();
        }
    }

    public static boolean help(int[] s, int a, int b) {
        int[][] tot = new int[b][a];
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < a; j++) {
                tot[i][j] = s[i * a + j];
            }
        }
        for (int i = 0; i < b; i++) {
            if (Arrays.stream(tot[i]).sum() == b) {
                return true;
            }
        }
        return false;
    }
}

