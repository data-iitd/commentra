import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] m = new int[368];
        int[] f = new int[368];
        for (int i = 0; i < n; i++) {
            String[] s = sc.next().split(" ");
            int a = Integer.parseInt(s[1]);
            int b = Integer.parseInt(s[2]) + 1;
            if (s[0].equals("M")) {
                m[a] += 2;
                m[b] -= 2;
            } else {
                f[a] += 2;
                f[b] -= 2;
            }
        }
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < 368; i++) {
            a += m[i];
            b += f[i];
            c = Math.min(a, b);
        }
        System.out.println(c);
    }
}
