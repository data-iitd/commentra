import java.util.*;

public class Main {
    static int inf = 10_000_000_000;
    static double eps = 1.0 / 10_000_000_000;
    static int mod = 1_000_000_007;
    static int[] dd = {-1, 0, 1, 0, -1, -1, 1, 1};
    static int[] ddn = {-1, 0, 1, 1, 1, 0, -1, -1};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int k = scanner.nextInt();
        int l = 0;
        for (char c : s.toCharArray()) {
            if (c != '1') {
                break;
            }
            l++;
        }
        if (l >= k) {
            System.out.println(1);
        } else {
            System.out.println(s.charAt(l));
        }
    }
}
