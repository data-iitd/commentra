import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> as = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            as.add(scanner.nextInt());
        }
        List<Integer> xs = new ArrayList<>();
        xs.add(as.get(0));
        for (int j = 1; j < n; j++) {
            int asJ = as.get(j);
            int idx = binarySearch(xs, asJ);
            if (idx == xs.size()) {
                xs.add(asJ);
            } else {
                xs.set(idx, asJ);
            }
        }
        System.out.println(xs.size());
    }

    private static int binarySearch(List<Integer> list, int target) {
        int left = 0;
        int right = list.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (list.get(mid) < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
