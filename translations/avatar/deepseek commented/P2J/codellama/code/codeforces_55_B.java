public class Solution {
    public static void rememberTheNumber(int[] nums, int i, String[] operations, int[] ans) {
        // If the index i is greater than or equal to 3, return to limit recursion depth
        if (i >= 3) {
            return;
        }
        
        // Iterate over pairs of numbers to perform operations
        for (int j = 0; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                if (nums[j] != -1 && nums[k] != -1) {
                    int s = nums[j];
                    nums[j] = -1;  // Mark the number as used
                    int t = nums[k];
                    
                    // Perform the operation based on the current operation symbol
                    if (operations[i].equals("+")) {
                        nums[k] = s + t;
                    } else if (operations[i].equals("*")) {
                        nums[k] = s * t;
                    }
                    
                    // If it's the last operation and the result is smaller than the current minimum, update ans
                    if (i == 2 && nums[k] < ans[0]) {
                        ans[0] = nums[k];
                    }
                    
                    // Recursively call the function with updated parameters
                    rememberTheNumber(nums, i + 1, operations, ans);
                    
                    // Restore the original numbers to try other combinations
                    nums[j] = s;
                    nums[k] = t;
                }
            }
        }
    }
    
    public static void main(String[] args) {
        // Read input numbers and operations
        int[] nums = Arrays.stream(System.console().readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        String[] operations = System.console().readLine().split(" ");
        
        // Initialize the answer list with a large number
        int[] ans = new int[] {10000000000000000000000000};
        
        // Call the function with initial parameters
        rememberTheNumber(nums, 0, operations, ans);
        
        // Print the smallest number found
        System.out.println(ans[0]);
    }
}
