import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            int m = sc.nextInt();
            int n = sc.nextInt();
            Vector<Integer> book = new Vector<Integer>();
            for (int i = 0; i < n; i++) {
                int tmp = sc.nextInt();
                book.add(tmp);
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
    public static boolean check(int n, int wei, Vector<Integer> book) {
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
}

