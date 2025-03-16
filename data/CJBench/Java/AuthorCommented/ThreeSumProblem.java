
import java.util.*;

/**
 * Program to find all unique triplets in the array that sum to a target value.
 */
public class ThreeSumProblem {

    /**
     * Two-pointer approach to find unique triplets that sum up to the target value.
     *
     * @param nums   The input array
     * @param target The target sum
     * @return A list of unique triplets
     */
    public List<List<Integer>> twoPointer(int[] nums, int target) {
        Arrays.sort(nums); // Sort the array for the two-pointer approach
        List<List<Integer>> result = new ArrayList<>();

        for (int i = 0; i < nums.length - 2; i++) {
            // Avoid duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1, right = nums.length - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == target) {
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    left++;
                    right--;

                    // Avoid duplicates for the second and third numbers
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }

    /**
     * Main method for user input and output.
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the size of the array
        int n = sc.nextInt();
        int[] nums = new int[n];

        // Read the elements of the array
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        // Read the target sum
        int target = sc.nextInt();

        // Solve the problem using the two-pointer approach
        ThreeSumProblem tsp = new ThreeSumProblem();
        List<List<Integer>> result = tsp.twoPointer(nums, target);

        // Print the results
        if (result.isEmpty()) {
            System.out.println("No triplets found.");
        } else {
            for (List<Integer> triplet : result) {
                System.out.println(triplet);
            }
        }

        sc.close();
    }
}
