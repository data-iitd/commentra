import java.util.*;

public class Main {
    // Method to find all unique triplets in the array that sum up to the target
    public List<List<Integer>> twoPointer(int[] nums, int target) {
        // Sort the input array to facilitate the two-pointer approach
        Arrays.sort(nums); 
        // Initialize a list to hold the resulting triplets
        List<List<Integer>> result = new ArrayList<>();
        
        // Iterate through the array, considering each element as a potential first element of a triplet
        for (int i = 0; i < nums.length - 2; i++) {
            // Skip duplicate elements to avoid duplicate triplets in the result
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // Initialize two pointers: one at the next element and one at the end of the array
            int left = i + 1, right = nums.length - 1;
            
            // Use the two-pointer technique to find pairs that complement the current element to reach the target
            while (left < right) {
                // Calculate the sum of the current triplet
                int sum = nums[i] + nums[left] + nums[right];
                
                // Check if the sum matches the target
                if (sum == target) {
                    // If a valid triplet is found, add it to the result list
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    // Move both pointers inward to look for new pairs
                    left++;
                    right--;
                    
                    // Skip duplicate elements on the left to avoid duplicate triplets
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    // Skip duplicate elements on the right to avoid duplicate triplets
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } 
                // If the sum is less than the target, move the left pointer to increase the sum
                else if (sum < target) {
                    left++;
                } 
                // If the sum is greater than the target, move the right pointer to decrease the sum
                else {
                    right--;
                }
            }
        }
        // Return the list of unique triplets that sum to the target
        return result;
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements in the array
        int n = sc.nextInt();
        int[] nums = new int[n];
        
        // Read the elements of the array
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        
        // Read the target sum
        int target = sc.nextInt();
        
        // Create an instance of the Main class to access the twoPointer method
        Main tsp = new Main();
        
        // Call the twoPointer method to find the triplets and store the result
        List<List<Integer>> result = tsp.twoPointer(nums, target);
        
        // Check if any triplets were found and print the result
        if (result.isEmpty()) {
            System.out.println("No triplets found.");
        } else {
            for (List<Integer> triplet : result) {
                System.out.println(triplet);
            }
        }
        
        // Close the scanner to prevent resource leaks
        sc.close();
    }
}
