import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Vector<Integer> p = new Vector<>(n);
        for (int i = 0; i < n; i++) {
            p.add(scanner.nextInt());
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (p.get(i) == i + 1) {
                p.set(i + 1, p.get(i));
                ans += 1;
            }
        }
        if (p.get(n - 1) == n) {
            ans += 1;
        }
        System.out.println(ans);
    }
}
