
import java.util.Scanner;
import java.util.Vector;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Vector<Integer> p = new Vector<Integer>();
        for (int i = 0; i < n; i++) {
            p.add(sc.nextInt());
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (p.get(i) == i + 1) {
                p.set(i + 1, p.get(i));
                ans++;
            }
        }
        if (p.get(n - 1) == n) {
            ans++;
        }
        System.out.println(ans);
    }
}

