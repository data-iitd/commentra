import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements
        int N = sc.nextInt();
        
        // Initialize an empty list to hold the subsequences
        List<List<Integer>> ans = new ArrayList<>();
        
        // Iterate over the range of N to read each element
        for (int i = 0; i < N; i++) {
            int A = sc.nextInt();  // Read the current element
            int idx = binarySearch(ans, A);  // Find the position to insert the element
            
            // If the index is equal to the length of ans, it means A is greater than all elements
            if (idx == ans.size()) {
                ans.add(new ArrayList<>(Arrays.asList(A)));  // Start a new subsequence with A
            } else {
                // Otherwise, append A to the existing subsequence at index idx
                ans.get(idx).add(A);
            }
        }
        
        // Print the number of subsequences formed
        System.out.println(ans.size());
    }
    
    // Binary search to find the position to insert the element
    private static int binarySearch(List<List<Integer>> ans, int A) {
        int bad = -1, good = ans.size();
        
        // Continue searching while there is more than one element in the range
        while (good - bad > 1) {
            int mid = (bad + good) / 2;  // Calculate the middle index
            // If the last element of the mid list is less than the key, move the good boundary
            if (ans.get(mid).get(ans.get(mid).size() - 1) < A) {
                good = mid;
            } else {
                // Otherwise, move the bad boundary
                bad = mid;
            }
        }
        
        // Return the index where the key should be inserted
        return good;
    }
}

