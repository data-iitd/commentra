
import java.util.Scanner;
public final class RangeInSortedArray {
    private RangeInSortedArray() {
    }
    public static int[] sortedRange(int[] nums, int key) {
        int[] range = new int[] {-1, -1};
        alteredBinSearchIter(nums, key, 0, nums.length - 1, range, true);
        alteredBinSearchIter(nums, key, 0, nums.length - 1, range, false);
        return range;
    }
    public static void alteredBinSearchIter(int[] nums, int key, int left, int right, int[] range, boolean goLeft) {
        while (left <= right) {
            final int mid = (left + right) >>> 1;
            if (nums[mid] > key) {
                right = mid - 1;
            } else if (nums[mid] < key) {
                left = mid + 1;
            } else {
                if (goLeft) {
                    if (mid == 0 || nums[mid - 1] != key) {
                        range[0] = mid;
                        return;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    if (mid == nums.length - 1 || nums[mid + 1] != key) {
                        range[1] = mid;
                        return;
                    } else {
                        left = mid + 1;
                    }
                }
            }
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        int key = scanner.nextInt();
        int[] range = sortedRange(nums, key);
        System.out.println(range[0] + " " + range[1]);
        scanner.close();
    }
}
