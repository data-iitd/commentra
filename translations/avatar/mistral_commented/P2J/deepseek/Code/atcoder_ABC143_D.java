import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        Arrays.sort(l);
        long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = l[i];
                int b = l[j];
                int right = binarySearchRight(l, a + b);
                int left = binarySearchLeft(l, Math.max(a - b, b - a));
                int tmp = Math.max(0, right - left);
                if (left <= i && i < right) {
                    tmp--;
                }
                if (left <= j && j < right) {
                    tmp--;
                }
                ans += tmp;
            }
        }
        System.out.println(ans / 3);
    }

    private static int binarySearchRight(int[] arr, int value) {
        int low = 0;
        int high = arr.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= value) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    private static int binarySearchLeft(int[] arr, int value) {
        int low = 0;
        int high = arr.length;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] < value) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}
