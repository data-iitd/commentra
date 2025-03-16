import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void rememberTheNumber(List<Integer> nums, int i, List<String> operations, List<Long> ans) {
        // If the index i is greater than or equal to 3, return to limit recursion depth
        if (i >= 3) {
            return;
        }

        // Iterate over pairs of numbers to perform operations
        for (int j = 0; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                if (nums.get(j) != -1 && nums.get(k) != -1) {
                    int s = nums.get(j);
                    nums.set(j, -1);  // Mark the number as used
                    int t = nums.get(k);

                    // Perform the operation based on the current operation symbol
                    if (operations.get(i).equals("+")) {
                        nums.set(k, s + t);
                    } else if (operations.get(i).equals("*")) {
                        nums.set(k, s * t);
                    }

                    // If it's the last operation and the result is smaller than the current minimum, update ans
                    if (i == 2 && nums.get(k) < ans.get(0)) {
                        ans.set(0, nums.get(k));
                    }

                    // Recursively call the function with updated parameters
                    rememberTheNumber(nums, i + 1, operations, ans);

                    // Restore the original numbers to try other combinations
                    nums.set(j, s);
                    nums.set(k, t);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Integer> nums = new ArrayList<>();
        List<String> operations = new ArrayList<>();

        // Read input numbers and operations
        String[] numsInput = scanner.nextLine().split(" ");
        for (String num : numsInput) {
            nums.add(Integer.parseInt(num));
        }
        String[] operationsInput = scanner.nextLine().split(" ");
        for (String operation : operationsInput) {
            operations.add(operation);
        }

        // Initialize the answer list with a large number
        List<Long> ans = new ArrayList<>();
        ans.add(1000000000000000000L);

        // Call the function with initial parameters
        rememberTheNumber(nums, 0, operations, ans);

        // Print the smallest number found
        System.out.println(ans.get(0));
    }
}
