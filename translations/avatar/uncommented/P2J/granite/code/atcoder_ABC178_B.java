
import java.util.*;
import java.io.*;

class atcoder_ABC178_B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int a = Integer.parseInt(s[0]);
        int b = Integer.parseInt(s[1]);
        int c = Integer.parseInt(s[2]);
        int d = Integer.parseInt(s[3]);
        int ans = Math.max(a * c, Math.max(b * d, Math.max(a * d, b * c)));
        System.out.println(ans);
    }
}
