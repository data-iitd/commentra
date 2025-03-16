import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int len = 5;
        int[] l = scanNums(sc, len);
        System.out.println(min(pattern1(l), pattern2(l), pattern3(l)));
    }

    private static int[] scanNums(Scanner sc, int len) {
        int[] nums = new int[len];
        for (int i = 0; i < len; i++) {
            nums[i] = sc.nextInt();
        }
        return nums;
    }

    private static int pattern1(int[] l) {
        return (l[0] * l[3]) + (l[1] * l[4]);
    }

    private static int pattern2(int[] l) {
        return 2 * l[2] * max(l[3], l[4]);
    }

    private static int pattern3(int[] l) {
        return 2 * l[2] * min(l[3], l[4]) + doch(l);
    }

    private static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("Function min() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.min(res, num);
        }
        return res;
    }

    private static int max(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("Function max() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.max(res, num);
        }
        return res;
    }

    private static int doch(int[] l) {
        if (l[3] > l[4]) {
            return l[0] * (l[3] - l[4]);
        } else {
            return l[1] * (l[4] - l[3]);
        }
    }
}
//<END-OF-CODE>
