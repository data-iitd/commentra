
import java.util.Arrays;
import java.util.Scanner;

public class atcoder_ABC155_D{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        Arrays.sort(a);
        long ll = -1000000000L;
        long rr = 1000000000L;
        while (ll + 1 < rr) {
            long x = (ll + rr) / 2;
            long tot = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] < 0) {
                    int l = -1, r = n;
                    while (l + 1 < r) {
                        int c = (l + r) / 2;
                        if (a[i] * a[c] < x) {
                            r = c;
                        } else {
                            l = c;
                        }
                    }
                    tot += n - r;
                } else {
                    int l = -1, r = n;
                    while (l + 1 < r) {
                        int c = (l + r) / 2;
                        if (a[i] * a[c] < x) {
                            l = c;
                        } else {
                            r = c;
                        }
                    }
                    tot += r;
                }
                if (a[i] * a[i] < x) {
                    tot--;
                }
            }
            tot /= 2;
            if (tot < k) {
                ll = x;
            } else {
                rr = x;
            }
        }
        System.out.println(ll);
    }
}
