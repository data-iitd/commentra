import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        int x = Math.max(a.length(), b.length());
        a = a.replace('0', '2');
        b = b.replace('0', '2');
        a = a.replace('1', '0');
        b = b.replace('1', '0');
        a = a.replace('2', '1');
        b = b.replace('2', '1');
        a = a.replace('0','');
        b = b.replace('0','');
        a = a.replace('1', '0');
        b = b.replace('1', '0');
        a = a.replace(' ', '1');
        b = b.replace(' ', '1');
        String s = "";
        int c = 0;
        for (int i = 0; i < x; i++) {
            int d = (int) (b.charAt(i) - '0') + (int) (a.charAt(x - i - 1) - '0') + c;
            if (d > 9) {
                s += (char) (d - 10 + '0');
                c = 1;
            } else {
                s += (char) (d + '0');
                c = 0;
            }
        }
        if (c == 1) {
            s += '1';
        }
        System.out.println(new StringBuilder(s).reverse().toString());
    }
}
