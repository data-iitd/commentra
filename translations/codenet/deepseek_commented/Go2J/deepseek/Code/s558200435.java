import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // 1. Reading the input number of elements (n)

        int[] a = new int[n]; // 2. Reading the elements into an array (a)
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        List<Integer> b = new ArrayList<>(); // 3. Creating a list (b) to store the longest increasing subsequence
        for (int v : a) { // 4. Finding the longest increasing subsequence
            int x = binarySearch(b, v);
            if (x == b.size()) {
                b.add(v);
            } else {
                b.set(x, v);
            }
        }

        System.out.println(b.size()); // 5. Outputting the length of the longest increasing subsequence
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
