import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers n and k from input
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read a list of n integers from input
        List<Integer> elems = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            elems.add(scanner.nextInt());
        }
        
        // Define a lambda function to check if all elements in an array are the same
        java.util.function.Predicate<List<Integer>> allSame = arr -> {
            int first = arr.get(0);
            for (int x : arr) {
                if (x != first) {
                    return false;
                }
            }
            return true;
        };
        
        // If all elements in elems are the same, print 0 and exit
        if (allSame.test(elems)) {
            System.out.println(0);
            return;
        }
        
        // If k is 1, it's impossible to satisfy the conditions, print -1 and exit
        if (k == 1) {
            System.out.println(-1);
            return;
        }
        
        // If the last k-1 elements are not the same, print -1 and exit
        List<Integer> lastKMinusOne = elems.subList(k - 1, elems.size());
        if (!allSame.test(lastKMinusOne)) {
            System.out.println(-1);
            return;
        }
        
        // Set the target value to the last element of elems
        int target = elems.get(elems.size() - 1);
        
        // Create a list of elements to delete, which are the first k-1 elements
        List<Integer> toDelete = elems.subList(0, k - 1);
        
        // Remove elements from to_delete that are equal to the target from the end
        while (!toDelete.isEmpty() && toDelete.get(toDelete.size() - 1) == target) {
            toDelete.remove(toDelete.size() - 1);
        }
        
        // Print the number of elements that need to be deleted
        System.out.println(toDelete.size());
    }
}
