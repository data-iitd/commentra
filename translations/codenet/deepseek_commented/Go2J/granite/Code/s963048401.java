
import java.util.*;

public class s963048401{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }
        
        // Initialize xs with the first element of as
        List<Integer> xs = new ArrayList<>();
        xs.add(as[0]);
        for (int j = 1; j < n; j++) {
            // Use Collections.binarySearch to find the position to insert the current element
            int idx = Collections.binarySearch(xs, as[j]);
            if (idx < 0) {
                // If the element is larger than all elements in xs, add it
                idx = ~idx;
                xs.add(idx, as[j]);
            } else {
                // Otherwise, replace the existing element at the found position
                xs.set(idx, as[j]);
            }
        }
        
        // Print the length of the longest increasing subsequence found
        System.out.println(xs.size());
    }
}
