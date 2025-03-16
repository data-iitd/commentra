
import java.util.*;
import java.io.*;

class s973217665 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            String[] s = br.readLine().split(" ");
            int p = Integer.parseInt(s[0]);
            int q = Integer.parseInt(s[1]);
            int l = (int)Math.sqrt(p*p + q*q);
            boolean isprime = true;
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < l; j++) {
                    int x = i*i + j*j;
                    if (x <= 1 || x >= p*p + q*q) continue;
                    if ((i*p + j*q) % x == 0 && (i*q - j*p) % x == 0) isprime = false;
                }
            }
            System.out.println(isprime? "P" : "C");
        }
    }
}

