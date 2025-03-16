import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] s = new int[m];
        int[] c = new int[m];
        for (int i = 0; i < m; i++) {
            s[i] = scanner.nextInt() - 1;
            c[i] = scanner.nextInt();
        }
        for (int i = 0; i < 1000; i++) {
            String st = String.valueOf(i);
            if (st.length() != n) {
                continue;
            }
            boolean f = true;
            for (int j = 0; j < m; j++) {
                if (st.charAt(s[j]) != (char) (c[j] + '0')) {
                    f = false;
                }
            }
            if (f) {
                System.out.println(i);
                return;
            }
        }
        System.out.println(-1);
    }
}
