
import java.util.*;

public class Main {
    // Method to find triplet with given sum using two pointers approach
    public List<List<Integer>> twoPointer(int[] nums, int target) {
        // Sort the input array in ascending order
        Arrays.sort(nums);

        // Initialize an empty ArrayList to store the result
        List<List<Integer>> result = new ArrayList<>();

        // Iterate through the array from the first index to the last index - 2
        for (int i = 0; i < nums.length - 2; i++) {
            // If the current element is same as the previous element, skip it
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Initialize the left and right pointers
            int left = i + 1, right = nums.length - 1;

            // Two pointers approach to find the triplet with given sum
            while (left < right) {
                // Calculate the sum of the current triplet
                int sum = nums[i] + nums[left] + nums[right];

                // If the sum is equal to the target, add the triplet to the result
                if (sum == target) {
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));

                    // Move the left pointer to the next index and the right pointer to the previous index
                    left++;
                    right--;

                    // Skip the duplicate elements
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }

                // If the sum is less than the target, move the left pointer to the next index
                else if (sum < target) {
                    left++;
                }

                // If the sum is greater than the target, move the right pointer to the previous index
                else {
                    right--;
                }
            }
        }

        // Return the result
        return result;
    }

    // Main method to read the input and call the twoPointer method
    public static void main(String[] args) {
        // Initialize a Scanner object to read the input
        Scanner sc = new Scanner(System.in);

        // Read the size of the array and initialize the array
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        // Read the target sum
        int target = sc.nextInt();

        // Create an instance of the Main class and call the twoPointer method
        Main tsp = new Main();
        List<List<Integer>> result = tsp.twoPointer(nums, target);

        // Check if the result is empty and print the message accordingly
        if (result.isEmpty()) {
            System.out.println("No triplet found with the given sum.");
        } else {
            // Print the result if the result is not empty
            for (List<Integer> triplet : result) {
                System.out.println(triplet);
            }
        }

        // Close the Scanner object
        sc.close();
    }
}

