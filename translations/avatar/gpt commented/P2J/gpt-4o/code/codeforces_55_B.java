import java.util.Scanner;

public class RememberTheNumber {
    public static void rememberTheNumber(int[] nums, int i, char[] operations, long[] ans) {
        // Base case: If we have performed 3 operations, exit the function
        if (i >= 3) {
            return;
        }

        // Iterate through all pairs of numbers in the list
        for (int j = 0; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                // Check if both numbers are not marked as used (-1)
                if (nums[j] != -1 && nums[k] != -1) {
                    // Store the current values of nums[j] and nums[k]
                    int s = nums[j];
                    nums[j] = -1;  // Mark nums[j] as used
                    int t = nums[k];

                    // Perform the operation based on the current operation symbol
                    if (operations[i] == '+') {
                        nums[k] = s + t;  // Addition operation
                    } else if (operations[i] == '*') {
                        nums[k] = s * t;  // Multiplication operation
                    }

                    // If we are at the last operation and the result is less than the current minimum, update it
                    if (i == 2 && nums[k] < ans[0]) {
                        ans[0] = nums[k];
                    }

                    // Recursively call the function for the next operation
                    rememberTheNumber(nums, i + 1, operations, ans);

                    // Backtrack: Restore the original values of nums[j] and nums[k]
                    nums[j] = s;
                    nums[k] = t;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input numbers
        int[] nums = new int[4];
        for (int i = 0; i < 4; i++) {
            nums[i] = scanner.nextInt();
        }

        // Read input operations
        char[] operations = new char[3];
        for (int i = 0; i < 3; i++) {
            operations[i] = scanner.next().charAt(0);
        }

        // Initialize the answer with a very large number
        long[] ans = {Long.MAX_VALUE};

        // Start the recursive function with the initial parameters
        rememberTheNumber(nums, 0, operations, ans);

        // Print the minimum result found after all operations
        System.out.println(ans[0]);

        scanner.close();
    }
}

// <END-OF-CODE>
