
import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        Vector<Integer> a = new Vector<Integer>();
        Vector<Integer> cnt = new Vector<Integer>();
        for (int i = 0; i < SIZE; i++) {
            cnt.add(0);
        }
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            cnt.set(x, cnt.get(x) + 1);
        }
        for (int i = 0; i < cnt.size(); i++) {
            if (cnt.get(i) > 0) {
                a.add(cnt.get(i));
            }
        }
        int ans = 0;
        for (int i = 0; i < a.size(); i++) {
            ans += a.get(i);
        }
        for (int i = 0; i < k; i++) {
            ans += a.get(i);
        }
        System.out.println(ans);
    }
}

