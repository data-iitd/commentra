import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        ArrayList<Integer> l = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            l.add(scanner.nextInt());
        }

        Collections.sort(l);

        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans += l.get(n - 1 - i);
        }

        System.out.println(ans);
    }
}
