

import java.util.*;
import java.io.*;

public class codeforces_242_B{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int id = 0;
        int l = Integer.parseInt(br.readLine().split(" ")[0]);
        int r = Integer.parseInt(br.readLine().split(" ")[1]);
        for (int i = 1; i < n; i++) {
            String[] temp = br.readLine().split(" ");
            int li = Integer.parseInt(temp[0]);
            int ri = Integer.parseInt(temp[1]);
            if (li <= l && r <= ri) {
                id = i;
            } else if (li < l || r < ri) {
                id = n;
            }
            l = Math.min(l, li);
            r = Math.max(r, ri);
        }
        System.out.println(id == n? -1 : id + 1);
    }
}

