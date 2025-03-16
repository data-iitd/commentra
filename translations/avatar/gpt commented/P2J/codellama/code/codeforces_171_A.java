
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        int x = Math.max(a.length(), b.length());
        a = String.format("%" + x + "s", a).replace(' ', '0');
        b = String.format("%" + x + "s", b).replace(' ', '0');
        String s = "";
        int c = 0;
        for (int i = 0; i < x; i++) {
            int d = b.charAt(i) - '0' + a.charAt(x - i - 1) - '0' + c;
            if (d > 9) {
                s += d % 10;
                c = 1;
            } else {
                s += d;
                c = 0;
            }
        }
        if (c == 1) {
            s += "1";
        }
        System.out.println(Integer.parseInt(new StringBuilder(s).reverse().toString()));
    }
}

