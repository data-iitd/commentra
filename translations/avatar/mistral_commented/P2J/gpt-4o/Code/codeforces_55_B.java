import java.util.*;

public class RememberTheNumber {
    public static void rememberTheNumber(int[] nums, int i, char[] operations, long[] ans) {
        if (i >= 3) {
            return; // If the index 'i' is greater than or equal to 3, return.
        }

        for (int j = 0; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                if (nums[j] != -1 && nums[k] != -1) {
                    int s = nums[j]; // Store the value of nums[j]
                    nums[j] = -1; // Mark nums[j] as processed
                    int t = nums[k]; // Store the value of nums[k]

                    if (operations[i] == '+') {
                        nums[k] = s + t; // Perform addition
                    } else if (operations[i] == '*') {
                        nums[k] = s * t; // Perform multiplication
                    }

                    if (i == 2 && nums[k] < ans[0]) {
                        ans[0] = nums[k]; // Update the answer if condition is met
                    }

                    rememberTheNumber(nums, i + 1, operations, ans); // Recursive call

                    nums[j] = s; // Restore the original value of nums[j]
                    nums[k] = t; // Restore the original value of nums[k]
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int[] nums = new int[4];
        for (int i = 0; i < 4; i++) {
            nums[i] = scanner.nextInt(); // Read the list of numbers
        }
        
        char[] operations = new char[3];
        for (int i = 0; i < 3; i++) {
            operations[i] = scanner.next().charAt(0); // Read the list of operations
        }
        
        long[] ans = { Long.MAX_VALUE }; // Initialize the answer with a large number
        rememberTheNumber(nums, 0, operations, ans); // Call the function with initial index 0
        
        System.out.println(ans[0]); // Print the final answer
        scanner.close();
    }
}
// <END-OF-CODE>
