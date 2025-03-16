public class Solution {
    public static void rememberTheNumber(int[] nums, int i, String[] operations, int[] ans) {
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
                    nums[j] = -1; // Mark nums[j] as used
                    int t = nums[k];
                    
                    // Perform the operation based on the current operation symbol
                    if (operations[i].equals("+")) {
                        nums[k] = s + t; // Addition operation
                    } else if (operations[i].equals("*")) {
                        nums[k] = s * t; // Multiplication operation
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
        // Read input numbers and operations from the user
        int[] nums = Arrays.stream(System.console().readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        String[] operations = System.console().readLine().split(" ");
        
        // Initialize the answer with a very large number
        int[] ans = {10000000000000000000000000};
        
        // Start the recursive function with the initial parameters
        rememberTheNumber(nums, 0, operations, ans);
        
        // Print the minimum result found after all operations
        System.out.println(ans[0]);
    }
}
