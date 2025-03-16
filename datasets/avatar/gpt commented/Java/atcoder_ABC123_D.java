import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Initialize scanner for user input
        Scanner sc = new Scanner(System.in);
        
        // Create an array to store the sizes of three lists
        int x[] = new int[3];
        int max = 0; // Variable to track the maximum size
        
        // Read the sizes of the three lists from user input
        for (int i = 0; i < 3; ++i) {
            x[i] = sc.nextInt();
            max = Math.max(max, x[i]); // Update max if current size is greater
        }
        
        // Read the maximum product limit
        int k = sc.nextInt();
        
        // Initialize an array of lists to store the elements for each of the three lists
        List<Long> a[] = new List[3];
        for (int i = 0; i < 3; ++i) {
            a[i] = new ArrayList<Long>();
        }
        
        // Read the elements for each list and sort them
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < x[i]; ++j) {
                a[i].add(sc.nextLong()); // Add elements to the respective list
            }
            Collections.sort(a[i]); // Sort the list after all elements are added
        }
        
        // Close the scanner as we no longer need input
        sc.close();
        
        // List to store the valid sums
        List<Long> ans = new ArrayList<Long>();
        
        // Generate all combinations of elements from the three lists
        for (int i = 0; i < x[0]; ++i) {
            for (int j = 0; j < x[1]; ++j) {
                for (int m = 0; m < x[2]; ++m) {
                    // Check if the product of the indices is within the limit k
                    if ((i + 1) * (j + 1) * (m + 1) <= k) {
                        // Calculate the sum of the selected elements from each list
                        long tmp = a[0].get(x[0] - i - 1) + a[1].get(x[1] - j - 1) + a[2].get(x[2] - m - 1);
                        ans.add(tmp); // Add the sum to the answer list
                    }
                }
            }
        }
        
        // Sort the list of sums in ascending order
        Collections.sort(ans);
        
        // Get the size of the answer list
        int n = ans.size();
        
        // Print the largest k sums from the answer list
        for (int i = 0; i < k; ++i) {
            System.out.println(ans.get(n - i - 1)); // Print the k largest sums
        }
    }
}
