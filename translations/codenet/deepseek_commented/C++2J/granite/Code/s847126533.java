
import java.util.Scanner;
import java.util.Arrays;

public class s847126533{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            int m = sc.nextInt();
            int n = sc.nextInt();
            if (m == 0 && n == 0) {
                break;
            }
            int[] book = new int[n];
            for (int i = 0; i < n; i++) {
                book[i] = sc.nextInt();
            }

            // Binary search to find the maximum weight a person can carry
            int l = 0;
            int r = 1500000;
            int ans;
            while (l < r) {
                int mid = (l + r) / 2;
                if (check(m, mid, book)) {
                    ans = mid;
                    r = mid; // Adjust the right boundary
                } else {
                    l = mid; // Adjust the left boundary
                }
            }
            System.out.println(ans);
        }
    }

    // Function to check if it's possible to carry all books with n people and a given weight limit
    public static boolean check(int n, int wei, int[] book) {
        int tmp = wei;
        n--;
        for (int i = 0; i < book.length; i++) {
            if (tmp < book[i]) {
                if (n > 0) {
                    n--;
                    tmp = wei;
                    if (tmp < book[i])
                        return false;
                } else {
                    return false;
                }
            }
            tmp -= book[i];
        }
        return true;
    }
}
