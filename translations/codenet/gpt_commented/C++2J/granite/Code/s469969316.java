
import java.util.Scanner;

public class s469969316{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String input = sc.next();
            if (input.equals(".")) break;
            int[] a = new int[3];
            int cnt = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        a[0] = i;
                        a[1] = j;
                        a[2] = k;
                        String ss = input;
                        for (int l = 0; l < 3; l++) {
                            if (ss.contains("P" + l)) ss = ss.replace("P" + l, String.valueOf(a[l]));
                            if (ss.contains("Q" + l)) ss = ss.replace("Q" + l, String.valueOf(a[l]));
                            if (ss.contains("R" + l)) ss = ss.replace("R" + l, String.valueOf(a[l]));
                        }
                        int it = 0;
                        cnt += eval(ss, it) == 2? 1 : 0;
                    }
                }
            }
            System.out.println(cnt);
        }
    }

    public static int Not(int x) {
        return 2 - x;
    }

    public static int And(int x, int y) {
        if (x * y == 0) return 0;
        if (x == 2 && y == 2) return 2;
        return 1;
    }

    public static int Or(int x, int y) {
        if (x == 2 || y == 2) return 2;
        if (x == 1 || y == 1) return 1;
        return 0;
    }

    public static int eval(String ss, int it) {
        char c = ss.charAt(it++);
        if ('0' <= c && c <= '2') return c - '0';
        if (c == '-') return Not(eval(ss, it));
        int x = eval(ss, it);
        c = ss.charAt(it++);
        int y = eval(ss, it);
        ++it;
        return c == '*'? And(x, y) : Or(x, y);
    }
}
