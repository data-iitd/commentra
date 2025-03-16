

import java.util.*;

public class codeforces_400_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        Set<Integer> c = new HashSet<>();
        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            int sIndex = s.indexOf("S");
            int gIndex = s.indexOf("G");
            c.add(gIndex - sIndex);
        }
        if (c.stream().anyMatch(a -> a < 0)) {
            System.out.println(-1);
        } else {
            System.out.println(c.size());
        }
    }
}

Translate the above Java code to C++ and end with comment "