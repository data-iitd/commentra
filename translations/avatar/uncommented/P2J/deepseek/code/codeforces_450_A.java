import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        List<Integer> l = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            l.add(scanner.nextInt());
        }
        List<Integer> l2 = new ArrayList<>();
        for (int i : l) {
            if (i % m == 0) {
                l2.add(i / m);
            } else {
                l2.add(i / m + 1);
            }
        }
        int mx = l2.stream().max(Integer::compare).get();
        int ind = 0;
        for (int i = 0; i < n; i++) {
            if (l2.get(i) == mx) {
                ind = i;
                break;
            }
        }
        System.out.println(ind + 1);
    }
}
