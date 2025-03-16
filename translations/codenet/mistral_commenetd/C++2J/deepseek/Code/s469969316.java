import java.util.Scanner;

public class LogicalExpressionParser {
    static int[] a = new int[3];
    static int cnt;
    static String input, ss;
    static int it;

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

    static int parse() {
        char c = ss.charAt(it++);
        if ('0' <= c && c <= '2') return c - '0';
        if (c == '-') return Not(parse());

        int x = parse();
        c = ss.charAt(it++);
        int y = parse();
        it++;
        return c == '*' ? And(x, y) : Or(x, y);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext() && !scanner.nextLine().equals(".")) {
            input = scanner.nextLine();
            cnt = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        a[0] = i; a[1] = j; a[2] = k;
                        ss = input;
                        for (char c : ss.toCharArray()) {
                            if (c == 'P') ss = ss.replace('P', (char) (a[0] + '0'));
                            if (c == 'Q') ss = ss.replace('Q', (char) (a[1] + '0'));
                            if (c == 'R') ss = ss.replace('R', (char) (a[2] + '0'));
                        }
                        it = 0;
                        if (parse() == 2) cnt++;
                    }
                }
            }
            System.out.println(cnt);
        }
        scanner.close();
    }
}
