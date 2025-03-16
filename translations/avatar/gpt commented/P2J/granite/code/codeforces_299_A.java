
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
        int ans = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] % ans!= 0) {
                ans = -1;
                break;
            }
        }
        System.out.println(ans);
    }
}
