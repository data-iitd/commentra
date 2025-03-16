import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Function to check the minimum number of moves required
    public static int check(int k, List<Integer> lst_p, List<Integer> lst_m, int lastx, int lasty) {
        int ans = Integer.MAX_VALUE;

        for (int j = 0; j <= k; j++) {
            if (j > lastx || k - j > lasty) {
                continue;
            }

            int p = (j == 0) ? 0 : lst_p.get(j - 1);
            int m = (k - j == 0) ? 0 : lst_m.get(lasty - (k - j));

            ans = Math.min(ans, 2 * p + Math.abs(m));
            ans = Math.min(ans, p + 2 * Math.abs(m));
        }

        return ans;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Taking the number of elements N and the number of queries K as input
        int N = scanner.nextInt();
        int K = scanner.nextInt();

        // Creating a list to store the numbers
        List<Integer> lst = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            lst.add(scanner.nextInt());
        }

        List<Integer> lst_p = new ArrayList<>();
        List<Integer> lst_m = new ArrayList<>();

        // Iterating through the list to find positive and negative numbers
        for (int i = 0; i < N; i++) {
            if (lst.get(i) == 0) {
                K--;
            } else if (lst.get(i) > 0) {
                lst_p.add(lst.get(i));
            } else {
                lst_m.add(lst.get(i));
            }
        }

        int lastx = lst_p.size();
        int lasty = lst_m.size();

        // Printing the minimum number of moves required
        System.out.println(check(K, lst_p, lst_m, lastx, lasty));

        scanner.close();
    }
}
// <END-OF-CODE>
