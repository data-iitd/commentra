
import java.util.Scanner;

public class atcoder_ABC150_C{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] numbers = new int[n];
        for (int i = 0; i < n; i++) {
            numbers[i] = i + 1;
        }

        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = scanner.nextInt();
        }

        int[] q = new int[n];
        for (int i = 0; i < n; i++) {
            q[i] = scanner.nextInt();
        }

        int pn = 0;
        int qn = 0;
        for (int i = 0; i < n; i++) {
            if (Arrays.equals(p, numbers)) {
                pn = i;
            }
            if (Arrays.equals(q, numbers)) {
                qn = i;
            }
            if (pn!= 0 && qn!= 0) {
                break;
            }
            nextPermutation(numbers);
        }

        System.out.println(Math.abs(pn - qn));
    }

    public static void nextPermutation(int[] nums) {
        int i = nums.length - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) {
            i--;
        }
        if (i <= 0) {
            reverse(nums, 0, nums.length - 1);
            return;
        }
        int j = nums.length - 1;
        while (nums[j] <= nums[i - 1]) {
            j--;
        }
        swap(nums, i - 1, j);
        reverse(nums, i, nums.length - 1);
    }

    public static void reverse(int[] nums, int start, int end) {
        while (start < end) {
            swap(nums, start, end);
            start++;
            end--;
        }
    }

    public static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
