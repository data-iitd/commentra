
import java.util.Scanner;

public class codeforces_171_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String a = scanner.next();
        String b = scanner.next();
        int x = Math.max(a.length(), b.length());
        a = a.substring(0, x).replace(" ", "0").replace("", "0");
        b = b.substring(0, x).replace(" ", "0").replace("", "0");
        StringBuilder s = new StringBuilder();
        int c = 0;
        for (int i = x - 1; i >= 0; i--) {
            int d = Integer.parseInt(String.valueOf(b.charAt(i))) + Integer.parseInt(String.valueOf(a.charAt(i))) + c;
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
        System.out.println(Integer.parseInt(s.reverse().toString()));
    }
}
