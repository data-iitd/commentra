
public class codeforces_55_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long[] nums = new long[4];
        String[] operations = new String[3];
        
        // Read input numbers and operations
        for (int i = 0; i < 4; i++) {
            nums[i] = scanner.nextLong();
        }
        for (int i = 0; i < 3; i++) {
            operations[i] = scanner.next();
        }
        
        // Initialize the answer variable with a large number
        long ans = 1000000000000000000L;
        
        // Call the recursive function with initial parameters
        rememberTheNumber(nums, operations, 0, ans);
        
        // Print the smallest number found
        System.out.println(ans);
    }
    
    // Recursive function to find the smallest number
    public static void rememberTheNumber(long[] nums, String[] operations, int i, long ans) {
        // If the index i is greater than or equal to 3, return to limit recursion depth
        if (i >= 3) {
            return;
        }
        
        // Iterate over pairs of numbers to perform operations
        for (int j = 0; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                if (nums[j]!= -1 && nums[k]!= -1) {
                    long s = nums[j];
                    nums[j] = -1;  // Mark the number as used
                    long t = nums[k];
                    
                    // Perform the operation based on the current operation symbol
                    if (operations[i].equals("+")) {
                        nums[k] = s + t;
                    } else if (operations[i].equals("*")) {
                        nums[k] = s * t;
                    }
                    
                    // If it's the last operation and the result is smaller than the current minimum, update ans
                    if (i == 2 && nums[k] < ans) {
                        ans = nums[k];
                    }
                    
                    // Recursively call the function with updated parameters
                    rememberTheNumber(nums, operations, i + 1, ans);
                    
                    // Restore the original numbers to try other combinations
                    nums[j] = s;
                    nums[k] = t;
                }
            }
        }
    }
}

// Translate the above Java code to C++ and end with comment "