import java.util.*;
public class Main {
    public List<List<Integer>> twoPointer(int[] nums, int target) {
        Arrays.sort(nums); // Sort the array to use the two-pointer technique
        List<List<Integer>> result = new ArrayList<>(); // Initialize a list to store the triplets
        for (int i = 0; i < nums.length - 2; i++) { // Iterate over the array to select the first element of the triplet
            if (i > 0 && nums[i] == nums[i - 1]) { // Skip duplicate values of nums[i]
                continue;
            }
            int left = i + 1, right = nums.length - 1; // Initialize two pointers, left and right
            while (left < right) { // Continue until the two pointers meet
                int sum = nums[i] + nums[left] + nums[right]; // Calculate the sum of the triplet
                if (sum == target) { // If the sum equals the target
                    result.add(Arrays.asList(nums[i], nums[left], nums[right])); // Add the triplet to the result list
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) { // Skip duplicates for left pointer
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) { // Skip duplicates for right pointer
                        right--;
                    }
                } else if (sum < target) { // If the sum is less than the target
                    left++; // Move the left pointer to the right
                } else { // If the sum is greater than the target
                    right--; // Move the right pointer to the left
                }
            }
        }
        return result; // Return the list of triplets
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Initialize a Scanner object to read input
        int n = sc.nextInt(); // Read the size of the array
        int[] nums = new int[n]; // Initialize the array with the given size
        for (int i = 0; i < n; i++) { // Read the elements of the array
            nums[i] = sc.nextInt();
        }
        int target = sc.nextInt(); // Read the target value
        Main tsp = new Main(); // Create an instance of the Main class
        List<List<Integer>> result = tsp.twoPointer(nums, target); // Call the twoPointer method to find the triplets
        if (result.isEmpty()) { // Check if the result list is empty
            System.out.println("No triplets found."); // Print a message if no triplets are found
        } else {
            for (List<Integer> triplet : result) { // Iterate over the result list and print each triplet
                System.out.println(triplet);
            }
        }
        sc.close(); // Close the Scanner object to free up resources
    }
}
