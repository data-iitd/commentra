import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] t = new int[n + 1];
        int[] a = new int[n + 1];
        int[] cnt = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            t[i] = scanner.nextInt();
        }

        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
        }

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
                crt.add(i);
                if (crt.size() > ans.size()) {
                    ans = new ArrayList<>(crt);
                }
            }
        }

        Collections.reverse(ans);

        System.out.println(ans.size());
        for (int i = 0; i < ans.size(); i++) {
            if (i > 0) {
                System.out.print(" ");
            }
            System.out.print(ans.get(i));
        }
        System.out.println();
    }
}
