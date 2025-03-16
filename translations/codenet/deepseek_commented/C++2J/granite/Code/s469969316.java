
import java.io.*;
import java.util.*;

class s469969316 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = br.readLine())!= null &&!line.equals(".")) {
            int cnt = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        String s = line.replace("P", String.valueOf(i)).replace("Q", String.valueOf(j)).replace("R", String.valueOf(k));
                        if (parse(s)) cnt++;
                    }
                }
            }
            System.out.println(cnt);
        }
    }

    static int it;
    static String ss;

    // Step 1: Define the Not function
    static int Not(int x) {
        return 2 - x;
    }

    // Step 2: Define the And function
    static int And(int x, int y) {
        if (x * y == 0) return 0;
        if (x == 2 && y == 2) return 2;
        return 1;
    }

    // Step 3: Define the Or function
    static int Or(int x, int y) {
        if (x == 2 || y == 2) return 2;
        if (x == 1 || y == 1) return 1;
        return 0;
    }

    // Step 4: Implement the parse function
    static boolean parse() {
        char c = ss.charAt(it++);
        if ('0' <= c && c <= '2') return c - '0' == 2;
        if (c == '-') return!parse();

        int x = parse();
        c = ss.charAt(it++);
        int y = parse();
        it++;
        return c == '*'? And(x, y) == 2 : Or(x, y) == 2;
    }
}

// Step 5: Output the count
// 