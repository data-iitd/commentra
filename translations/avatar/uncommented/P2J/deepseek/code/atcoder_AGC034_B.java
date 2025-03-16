import java.util.*;

public class Main {
    public static int gcd(int a, int b) {
        a = Math.max(a, b);
        b = Math.min(a, b);
        while (a % b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return b;
    }

    public static void solve() {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        StringBuilder t = new StringBuilder();
        int i = 0;
        while (i < s.length()) {
            if (s.charAt(i) == 'A') {
                t.append("A");
                i++;
            } else if (s.charAt(i) == 'B') {
                if (i < s.length() - 1) {
                    if (s.charAt(i + 1) == 'C') {
                        t.append("D");
                        i += 2;
                    } else {
                        t.append("X");
                        i++;
                    }
                } else {
                    t.append("X");
                    i++;
                }
            } else {
                t.append("X");
                i++;
            }
        }
        int total = 0;
        int numA = 0;
        for (int j = 0; j < t.length(); j++) {
            if (t.charAt(j) == 'X') {
                numA = 0;
            } else {
                if (t.charAt(j) == 'A') {
                    numA++;
                } else {
                    total += numA;
                }
            }
        }
        System.out.println(total);
    }

    public static void main(String[] args) {
        solve();
    }
}
