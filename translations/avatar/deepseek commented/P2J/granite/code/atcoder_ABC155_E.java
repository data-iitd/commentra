

import java.util.*;

public class atcoder_ABC155_E{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int pp = 0;
        int na = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int cc = na + Integer.parseInt(String.valueOf(s.charAt(i)));
            na = 0;
            if (cc <= 4) {
                pp += cc;
            } else {
                na = 1;
                if (i == 0) {
                    pp += 1;
                }
                pp += 10 - cc;
            }
        }
        System.out.println(pp);
    }
}

Translate the above Java code to C++ and end with comment "