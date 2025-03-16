

import java.util.*;
import java.io.*;

class s325320702 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int l = sc.nextInt();
        int r = sc.nextInt();
        int d = sc.nextInt();
        int ans = 0;
        for (int i = l; i <= r; i++) {
            if (i % d == 0) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}

Translate the above C code to Python and end with comment "