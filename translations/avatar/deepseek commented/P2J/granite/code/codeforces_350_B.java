

import java.util.*;

public class codeforces_350_B{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] t = new int[n + 1];
        int[] a = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            t[i] = sc.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
        }
        int[] cnt = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            cnt[a[i]]++;
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (t[i] == 1) {
                List<Integer> crt = new ArrayList<>();
                int x = a[i];
                while (cnt[x] == 1) {
                    crt.add(x);
                    x = a[x];
                }
                if (crt.size() > ans.size()) {
                    ans = crt;
                }
            }
        }
        Collections.reverse(ans);
        System.out.println(ans.size());
        for (int i : ans) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}

Translate the above Java code to C++ and end with comment "