import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            String input = sc.next();
            if (input.equals(".")) break;
            int[] a = new int[3];
            int cnt = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        a[0] = i; a[1] = j; a[2] = k;
                        String ss = input;
                        ss = ss.replace('P', "" + i);
                        ss = ss.replace('Q', "" + j);
                        ss = ss.replace('R', "" + k);
                        int it = 0;
                        if (parse(ss, it) == 2) cnt++;
                    }
                }
            }
            System.out.println(cnt);
        }
    }

    // Step 1: Define the Not function
    public static int Not(int x) {
        return 2-x;
    }

    // Step 2: Define the And function
    public static int And(int x, int y) {
        if (x*y == 0) return 0;
        if (x == 2 && y == 2) return 2;
        return 1;
    }

    // Step 3: Define the Or function
    public static int Or(int x, int y) {
        if (x == 2 || y == 2) return 2;
        if (x == 1 || y == 1) return 1;
        return 0;
    }

    // Step 4: Implement the parse function
    public static int parse(String ss, int it) {
        char c = ss.charAt(it++);
        if ('0' <= c && c <= '2') return c-'0';
        if (c == '-') return Not(parse(ss, it));

        int x = parse(ss, it);
        c = ss.charAt(it++);
        int y = parse(ss, it);
        ++it;
        return c == '*'? And(x, y) : Or(x, y);
    }
}

// Step 5: Implement the main function

// Step 6: Output the count

