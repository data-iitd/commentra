import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] t = new int[n + 1];
        int[] a = new int[n + 1];
        List<Integer> ans = new ArrayList<>();
        int[] cnt = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            t[i] = scanner.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
        }

        for (int i : a) {
            cnt[i]++;
        }

        for (int i = 1; i <= n; i++) {
            if (t[i] == 1) {
                List<Integer> crt = new ArrayList<>();
                int x = a[i];
                while (cnt[x] == 1) {
                    crt.add(x);
                    x = a[x];
                }
                if (crt.size() > ans.size()) {
                    ans = new ArrayList<>(crt);
                }
            }
        }

        java.util.Collections.reverse(ans);
        System.out.println(ans.size());
        for (int num : ans) {
            System.out.print(num + " ");
        }
    }
}
