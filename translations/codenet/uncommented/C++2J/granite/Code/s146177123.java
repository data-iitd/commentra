
import java.io.*;
import java.util.*;

public class s146177123{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = br.readLine())!= null) {
            int n = Integer.parseInt(line);
            if (n == -1) break;
            boolean[] st = new boolean[7];
            for (int i = 0; i < n; i++) {
                int t = Integer.parseInt(br.readLine());
                char[] ans = new char[8];
                for (int j = 0; j < 7; j++) {
                    ans[j] = (st[j] ^ seg[t][j])? '1' : '0';
                    st[j] = seg[t][j];
                }
                System.out.println(ans);
            }
        }
    }
}

