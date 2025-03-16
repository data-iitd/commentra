
import java.util.Scanner;

public class s090095029{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        boolean[] r0 = new boolean[n];
        int[] r1 = new int[n];
        int nr1 = 0;
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            if (a > b) {
                int t = a;
                a = b;
                b = t;
            }
            if (a == 1) r0[b - 1] = true;
            if (b == n) r1[nr1++] = a - 1;
        }
        boolean res = false;
        for (int i = 0; i < nr1; i++) {
            if (r0[r1[i]]) res = true;
        }
        System.out.println(res? "POSSIBLE" : "IMPOSSIBLE");
    }
}
