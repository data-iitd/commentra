import java.util.*;

public class RememberTheNumber {
    public static void rememberTheNumber(int[] nums, int i, char[] operations, long[] ans) {
        if (i >= 3) {
            return;
        }
        for (int j = 0; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                if (nums[j] != -1 && nums[k] != -1) {
                    int s = nums[j];
                    nums[j] = -1;
                    int t = nums[k];
                    if (operations[i] == '+') {
                        nums[k] = s + t;
                    } else if (operations[i] == '*') {
                        nums[k] = s * t;
                    }
                    if (i == 2 && nums[k] < ans[0]) {
                        ans[0] = nums[k];
                    }
                    rememberTheNumber(nums, i + 1, operations, ans);
                    nums[j] = s;
                    nums[k] = t;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] nums = new int[4];
        for (int i = 0; i < 4; i++) {
            nums[i] = scanner.nextInt();
        }
        char[] operations = new char[3];
        for (int i = 0; i < 3; i++) {
            operations[i] = scanner.next().charAt(0);
        }
        long[] ans = { Long.MAX_VALUE };
        rememberTheNumber(nums, 0, operations, ans);
        System.out.println(ans[0]);
        scanner.close();
    }
}

// <END-OF-CODE>
