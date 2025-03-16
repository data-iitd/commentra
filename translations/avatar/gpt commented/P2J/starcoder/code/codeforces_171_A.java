import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String a = sc.next();
        String b = sc.next();

        int x = Math.max(a.length(), b.length());

        a = a.replace("0", "").rjust(x, '0');
        b = b.replace("0", "").ljust(x, '0');

        String s = "";
        int c = 0;

        for (int i = 0; i < x; i++) {
            int d = Integer.parseInt(b.substring(i, i + 1)) + Integer.parseInt(a.substring(x - i - 1, x - i)) + c;

            if (d > 9) {
                s += d % 10;
                c = 1;
            } else {
                s += d;
                c = 0;
            }
        }

        if (c == 1) {
            s += 1;
        }

        System.out.println(s.replaceAll("^0*", ""));
    }
}

