import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements (n) and the parameter (k)
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read the list of elements
        int[] elems = new int[n];
        for (int i = 0; i < n; i++) {
            elems[i] = scanner.nextInt();
        }
        
        // Check if all elements in the array are the same
        boolean allSame = true;
        for (int i = 1; i < n; i++) {
            if (elems[i] != elems[0]) {
                allSame = false;
                break;
            }
        }
        
        // If all elements are the same, print 0 and return
        if (allSame) {
            System.out.println(0);
            return;
        }
        
        // If k is 1, print -1 and return
        if (k == 1) {
            System.out.println(-1);
            return;
        }
        
        // Check if elements from index k-1 to the end are all the same
        allSame = true;
        for (int i = k; i < n; i++) {
            if (elems[i] != elems[k - 1]) {
                allSame = false;
                break;
            }
        }
        
        // If not, print -1 and return
        if (!allSame) {
            System.out.println(-1);
            return;
        }
        
        // Set the target to the last element of the list
        int target = elems[n - 1];
        
        // Initialize to_delete as elements from the start to k-1
        List<Integer> toDelete = new ArrayList<>();
        for (int i = 0; i < k - 1; i++) {
            toDelete.add(elems[i]);
        }
        
        // Remove elements from to_delete that are equal to target until a different element is found
        while (!toDelete.isEmpty() && toDelete.get(toDelete.size() - 1) == target) {
            toDelete.remove(toDelete.size() - 1);
        }
        
        // Print the length of to_delete
        System.out.println(toDelete.size());
    }
}

// <END-OF-CODE>
