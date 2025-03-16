import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextInt());
        }

        List<Integer> b = new ArrayList<>();
        for (int v : a) {
            int x = binarySearch(b, v);
            if (x == b.size()) {
                b.add(v);
            } else {
                b.set(x, v);
            }
        }

        System.out.println(b.size());
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
