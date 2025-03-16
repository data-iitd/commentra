import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static boolean check(int n, int wei, List<Integer> book) {
        int tmp = wei;
        n--;
        for (int i = 0; i < book.size(); i++) {
            if (tmp < book.get(i)) {
                if (n > 0) {
                    n--;
                    tmp = wei;
                    if (tmp < book.get(i)) {
                        return false;
                    }
                } else {
                    return false;
                }
            }
            tmp -= book.get(i);
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m, n;
        while (scanner.hasNextInt()) {
            m = scanner.nextInt();
            n = scanner.nextInt();
            if (m == 0) break;

            List<Integer> book = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int tmp = scanner.nextInt();
                book.add(tmp);
            }

            int l = 0;
            int r = 1500000;
            int ans = 0;
            while (l < r) {
                if (check(m, (l + r) / 2, book)) {
                    ans = (l + r) / 2;
                    if (r == (l + r) / 2) break;
                    r = (l + r) / 2;
                } else {
                    if (l == (l + r) / 2) break;
                    l = (l + r) / 2;
                }
            }
            System.out.println(ans);
        }
        scanner.close();
    }
}
// <END-OF-CODE>
