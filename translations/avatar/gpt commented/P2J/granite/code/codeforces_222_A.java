
import java.util.Scanner;

public class codeforces_222_A{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers n and k from input
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read a list of n integers from input
        int[] elems = new int[n];
        for (int i = 0; i < n; i++) {
            elems[i] = scanner.nextInt();
        }
        
        // Define a lambda function to check if all elements in an array are the same
        boolean allSame = (arr) -> {
            for (int i = 0; i < arr.length; i++) {
                if (arr[i]!= arr[0]) {
                    return false;
                }
            }
            return true;
        };
        
        // If all elements in elems are the same, print 0 and exit
        if (allSame.apply(elems)) {
            System.out.println(0);
            return;
        }
        
        // If k is 1, it's impossible to satisfy the conditions, print -1 and exit
        if (k == 1) {
            System.out.println(-1);
            return;
        }
        
        // If the last k-1 elements are not the same, print -1 and exit
        if (!allSame.apply(elems.clone())) {
            System.out.println(-1);
            return;
        }
        
        // Set the target value to the last element of elems
        int target = elems[n - 1];
        
        // Create a list of elements to delete, which are the first k-1 elements
        int[] toDelete = new int[k - 1];
        System.arraycopy(elems, 0, toDelete, 0, k - 1);
        
        // Remove elements from toDelete that are equal to the target from the end
        int i = toDelete.length - 1;
        while (i >= 0 && toDelete[i] == target) {
            i--;
        }
        
        // Print the number of elements that need to be deleted
        System.out.println(toDelete.length - i - 1);
    }
}

Translate the above Java code to C++ and end with comment "