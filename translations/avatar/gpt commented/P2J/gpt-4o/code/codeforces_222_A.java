import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers n and k from input
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read a list of n integers from input
        int[] elems = new int[n];
        for (int i = 0; i < n; i++) {
            elems[i] = scanner.nextInt();
        }
        
        // Check if all elements in elems are the same
        boolean allSame = true;
        for (int i = 1; i < n; i++) {
            if (elems[i] != elems[0]) {
                allSame = false;
                break;
            }
        }
        
        // If all elements in elems are the same, print 0 and exit
        if (allSame) {
            System.out.println(0);
            return;
        }
        
        // If k is 1, it's impossible to satisfy the conditions, print -1 and exit
        if (k == 1) {
            System.out.println(-1);
            return;
        }
        
        // If the last k-1 elements are not the same, print -1 and exit
        boolean lastKSame = true;
        for (int i = k - 1; i < n; i++) {
            if (elems[i] != elems[k - 1]) {
                lastKSame = false;
                break;
            }
        }
        if (!lastKSame) {
            System.out.println(-1);
            return;
        }
        
        // Set the target value to the last element of elems
        int target = elems[n - 1];
        
        // Create a list of elements to delete, which are the first k-1 elements
        List<Integer> toDelete = new ArrayList<>();
        for (int i = 0; i < k - 1; i++) {
            toDelete.add(elems[i]);
        }
        
        // Remove elements from toDelete that are equal to the target from the end
        while (!toDelete.isEmpty() && toDelete.get(toDelete.size() - 1) == target) {
            toDelete.remove(toDelete.size() - 1);
        }
        
        // Print the number of elements that need to be deleted
        System.out.println(toDelete.size());
        
        scanner.close();
    }
}

// <END-OF-CODE>
