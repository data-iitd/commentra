
import java.util.*;

public class s353737529{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = "";

        if (n == 0) {
            System.out.println(0);
            return;
        }

        int i = 1;
        while (n!= 0) {
            if (n % 2 == 0) {
                s += "0";
            } else {
                s += "1";
            }

            n -= Math.abs(n % 2);
            n /= -2;
        }

        StringBuilder sb = new StringBuilder(s);
        s = sb.reverse().toString();

        System.out.println(s);
    }
}

Translate the above Java code to Python and end with comment "