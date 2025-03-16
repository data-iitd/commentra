import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class RememberTheNumber {
    public static void rememberTheNumber(List<Integer> nums, int i, List<String> operations, List<Long> ans) {
        if (i >= 3) {
            return;
        }

        for (int j = 0; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                if (nums.get(j) != -1 && nums.get(k) != -1) {
                    int s = nums.get(j);
                    nums.set(j, -1);
                    int t = nums.get(k);
                    nums.set(k, -1);
                    if (operations.get(i).equals("+")) {
                        nums.set(k, s + t);
                    } else if (operations.get(i).equals("*")) {
                        nums.set(k, s * t);
                    }
                    if (i == 2 && nums.get(k) < ans.get(0)) {
                        ans.set(0, nums.get(k));
                    }
                    rememberTheNumber(nums, i + 1, operations, ans);
                    nums.set(j, s);
                    nums.set(k, t);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Integer> nums = new ArrayList<>();
        String[] numsInput = scanner.nextLine().split(" ");
        for (String num : numsInput) {
            nums.add(Integer.parseInt(num));
        }

        List<String> operations = new ArrayList<>();
        String[] operationsInput = scanner.nextLine().split(" ");
        for (String operation : operationsInput) {
            operations.add(operation);
        }

        List<Long> ans = new ArrayList<>();
        ans.add(1000000000000000000L);
        rememberTheNumber(nums, 0, operations, ans);
        System.out.println(ans.get(0));
    }
}
