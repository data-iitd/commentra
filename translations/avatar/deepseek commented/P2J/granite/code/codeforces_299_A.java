

import java.util.*;
import java.io.*;

class codeforces_299_A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] s = br.readLine().split(" ");
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(s[i]);
        }
        Arrays.sort(a);
        if (a[0] == 1) {
            System.out.println(-1);
        } else {
            System.out.println(a[0]);
        }
    }
}

Translate the above Java code to C++ and end with comment "