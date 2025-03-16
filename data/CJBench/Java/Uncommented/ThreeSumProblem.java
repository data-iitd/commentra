
import java.util.*;
public class ThreeSumProblem {
    public List<List<Integer>> twoPointer(int[] nums, int target) {
        Arrays.sort(nums); 
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < nums.length - 2; i++) {
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
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        int target = sc.nextInt();
        ThreeSumProblem tsp = new ThreeSumProblem();
        List<List<Integer>> result = tsp.twoPointer(nums, target);
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
