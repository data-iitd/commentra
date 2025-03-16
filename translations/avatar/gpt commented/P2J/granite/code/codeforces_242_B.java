
import java.util.*;
import java.io.*;

public class codeforces_242_B{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int l = 0, r = 0;
        int id = 0;
        for (int i = 0; i < n; i++) {
            String[] split = br.readLine().split(" ");
            int li = Integer.parseInt(split[0]);
            int ri = Integer.parseInt(split[1]);
            if (li <= l && r <= ri) {
                id = i + 1;
            } else if (li < l || r < ri) {
                id = n + 1;
            }
            l = Math.min(l, li);
            r = Math.max(r, ri);
        }
        System.out.println(id == n + 1? -1 : id);
    }
}
