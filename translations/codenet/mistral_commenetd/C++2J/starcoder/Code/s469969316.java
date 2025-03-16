import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input, ss;
        int a[] = new int[3], it, cnt;
        while (true) {
            input = sc.next();
            if (input.equals(".")) break;
            cnt = 0;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    for (int k = 0; k < 3; k++) {
                        a[0] = i; a[1] = j; a[2] = k;
                        ss = input;
                        for (int l = 0; l < ss.length(); l++) {
                            if (ss.charAt(l) == 'P') ss = ss.substring(0, l) + (char)(a[0] + '0') + ss.substring(l+1);
                            if (ss.charAt(l) == 'Q') ss = ss.substring(0, l) + (char)(a[1] + '0') + ss.substring(l+1);
                            if (ss.charAt(l) == 'R') ss = ss.substring(0, l) + (char)(a[2] + '0') + ss.substring(l+1);
                        }
                        it = 0;
                        if (parse(ss) == 2) cnt++;
                    }
            System.out.println(cnt);
        }
    }

    static int parse(String ss) {
        char c = ss.charAt(it++);
        if ('0' <= c && c <= '2') return c - '0';
        if (c == '-') return Not(parse(ss));

        int x = parse(ss);
        c = ss.charAt(it++);
        int y = parse(ss);
        ++it;
        return c == '*'? And(x, y) : Or(x, y);
    }

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
}

