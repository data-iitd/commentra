import java.util.Scanner;

public class BooleanExpressionParser {
    static int Not(int x) {
        return 2 - x;
    }

    static int And(int x, int y) {
        if (x * y == 0) return 0;
        if (x == 2 && y == 2) return 2;
        return 1;
    }

    static int Or(int x, int y) {
        if (x == 2 || y == 2) return 2;
        if (x == 1 || y == 1) return 1;
        return 0;
    }

    static int parse(String ss, int[] a, int it) {
        char c = ss.charAt(it++);
        if ('0' <= c && c <= '2') return c - '0';
        if (c == '-') return Not(parse(ss, a, it));

        int x = parse(ss, a, it);
        c = ss.charAt(it++);
        int y = parse(ss, a, it);
        it++;
        return c == '*' ? And(x, y) : Or(x, y);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext() && !scanner.next().equals(".")) {
            int[] a = {0, 1, 2};
            int cnt = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        a[0] = i; a[1] = j; a[2] = k;
                        String ss = scanner.next();
                        for (int m = 0; m < ss.length(); m++) {
                            char c = ss.charAt(m);
                            if (c == 'P') ss = ss.substring(0, m) + a[0] + ss.substring(m + 1);
                            if (c == 'Q') ss = ss.substring(0, m) + a[1] + ss.substring(m + 1);
                            if (c == 'R') ss = ss.substring(0, m) + a[2] + ss.substring(m + 1);
                        }
                        int it = 0;
                        if (parse(ss, a, it) == 2) cnt++;
                    }
                }
            }
            System.out.println(cnt);
        }
        scanner.close();
    }
}
