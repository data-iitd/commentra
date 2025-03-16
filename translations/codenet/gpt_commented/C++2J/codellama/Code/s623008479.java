import java.util.Scanner;
import java.util.Vector;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        Vector<Integer> l = new Vector<Integer>();
        for (int i = 0; i < n; i++) {
            l.add(sc.nextInt());
        }
        sc.close();

        java.util.Collections.sort(l);

        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans += l.get(n - 1 - i);
        }

        System.out.println(ans);
    }
}
