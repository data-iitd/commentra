
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        int x = Math.max(a.length(), b.length());
        a = a.replace('0','').substring(x - a.length());
        b = b.replace('0','').substring(x - b.length());
        String s = "";
        int c = 0;
        for (int i = 0; i < x; i++) {
            int d = (b.charAt(i) - '0') + (a.charAt(x - i - 1) - '0') + c;
            if (d > 9) {
                s += d / 10;
                c = d % 10;
            } else {
                s += d;
                c = 0;
            }
        }
        if (c == 1) {
            s += 1;
        }
        System.out.println(s.replaceAll("^0+", ""));
    }
}

