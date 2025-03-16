import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    // Function to check if it's possible to carry all books with n people and a given weight limit
    public static boolean check(int n, int wei, List<Integer> book) {
        int tmp = wei;
        n--;
        for (int i = 0; i < book.size(); i++) {
            if (tmp < book.get(i)) {
                if (n > 0) {
                    n--;
                    tmp = wei;
                    if (tmp < book.get(i))
                        return false;
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
        while (scanner.hasNextInt()) {
            int m = scanner.nextInt();
            int n = scanner.nextInt();
            if (m == 0) break;

            List<Integer> book = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                book.add(scanner.nextInt());
            }

            // Binary search to find the maximum weight a person can carry
            int l = 0;
            int r = 1500000;
            int ans = 0;
            while (l < r) {
                int mid = (l + r) / 2;
                if (check(m, mid, book)) {
                    ans = mid;
                    r = mid; // Adjust the right boundary
                } else {
                    l = mid + 1; // Adjust the left boundary
                }
            }
            System.out.println(ans);
        }
        scanner.close();
    }
}
