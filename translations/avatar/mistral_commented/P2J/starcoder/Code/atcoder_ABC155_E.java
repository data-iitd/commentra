
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int pp = 0, na = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int cc = na + Integer.parseInt(s.charAt(i) + "");
            na = 0;
            if (cc <= 4) {
                pp += cc;
            } else {
                if (i == 0) {
                    pp += 1;
                } else {
                    pp += 10 - cc;
                }
            }
        }
        System.out.println(pp);
    }
}

