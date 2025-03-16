import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<List<Integer>> orig = new ArrayList<>();
        List<Integer> nums = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            nums.add(i);
        }
        permute(nums, 0, n - 1, orig);
        List<Integer> p = new ArrayList<>();
        List<Integer> q = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            p.add(scanner.nextInt());
        }
        for (int i = 0; i < n; i++) {
            q.add(scanner.nextInt());
        }
        int pn = orig.indexOf(p);
        int qn = orig.indexOf(q);
        System.out.println(Math.abs(pn - qn));
    }

    private static void permute(List<Integer> nums, int l, int r, List<List<Integer>> orig) {
        if (l == r) {
            orig.add(new ArrayList<>(nums));
        } else {
            for (int i = l; i <= r; i++) {
                java.util.Collections.swap(nums, l, i);
                permute(nums, l + 1, r, orig);
                java.util.Collections.swap(nums, l, i); // backtrack
            }
        }
    }
}
