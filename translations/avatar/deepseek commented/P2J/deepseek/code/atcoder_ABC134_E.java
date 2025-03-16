import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class BinarySearchExample {
    public static int binarySearch(int key, List<List<Integer>> ans) {
        // Initialize bad and good indices for binary search
        int bad = -1, good = ans.size();
        
        // Perform binary search to find the correct position
        while (good - bad > 1) {
            int mid = (bad + good) / 2;
            if (ans.get(mid).get(ans.get(mid).size() - 1) < key) {
                good = mid;
            } else {
                bad = mid;
            }
        }
        
        // Return the index where the key should be inserted
        return good;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int N = scanner.nextInt();
        
        // Initialize the list of lists
        List<List<Integer>> ans = new ArrayList<>();
        
        // Read each element and insert it into the appropriate position
        for (int i = 0; i < N; i++) {
            int A = scanner.nextInt();
            int idx = binarySearch(A, ans);
            if (idx == ans.size()) {
                // If the key should be inserted at the end, append a new sublist
                List<Integer> sublist = new ArrayList<>();
                sublist.add(A);
                ans.add(sublist);
            } else {
                // Otherwise, insert the key into the appropriate sublist
                ans.get(idx).add(A);
            }
        }
        
        // Print the number of unique elements
        System.out.println(ans.size());
    }
}
