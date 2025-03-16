import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        int x = Math.max(a.length(), b.length());
        a = a.replace("0", "2").replace("1", "0").replace("2", "1");
        b = b.replace("0", "2").replace("1", "0").replace("2", "1");
        a = a.substring(0, x).replace("0", "1").replace("1", "0");
        b = b.substring(0, x).replace("0", "1").replace("1", "0");
        int c = 0;
        StringBuilder s = new StringBuilder();
        for (int i = x - 1; i >= 0; i--) {
            int d = (b.charAt(i) - '0') + (a.charAt(i) - '0') + c;
            if (d > 9) {
                s.append(d % 10);
                c = 1;
            } else {
                s.append(d);
                c = 0;
            }
        }
        if (c == 1) {
            s.append(1);
        }
        System.out.println(s.reverse().toString().replace("0", "1").replace("1", "0"));
    }
}

