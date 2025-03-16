
import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements (n) and the parameter (k)
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        // Read the list of elements
        int[] elems = new int[n];
        for (int i = 0; i < n; i++) {
            elems[i] = sc.nextInt();
        }
        
        // Define a lambda function to check if all elements in a list are the same
        Predicate<int[]> all_same = arr -> {
            for (int i = 1; i < arr.length; i++) {
                if (arr[i]!= arr[0]) {
                    return false;
                }
            }
            return true;
        };
        
        // Check if all elements in the list are the same
        if (all_same.test(elems)) {
            // If all elements are the same, print 0 and return
            System.out.println(0);
            return;
        }
        
        // If k is 1, print -1 and return
        if (k == 1) {
            System.out.println(-1);
            return;
        }
        
        // Check if elements from index k-1 to the end are all the same
        if (!all_same.test(Arrays.copyOfRange(elems, k-1, elems.length))) {
            // If not, print -1 and return
            System.out.println(-1);
            return;
        }
        
        // Set the target to the last element of the list
        int target = elems[elems.length - 1];
        
        // Initialize to_delete as elements from the start to k-1
        int[] to_delete = Arrays.copyOfRange(elems, 0, k-1);
        
        // Remove elements from to_delete that are equal to target until a different element is found
        while (to_delete.length > 0 && to_delete[to_delete.length - 1] == target) {
            to_delete = Arrays.copyOfRange(to_delete, 0, to_delete.length - 1);
        }
        
        // Print the length of to_delete
        System.out.println(to_delete.length);
    }
}

