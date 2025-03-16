

import java.util.Scanner;

public class codeforces_222_A{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements (n) and the parameter (k)
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read the list of elements
        int[] elems = new int[n];
        for (int i = 0; i < n; i++) {
            elems[i] = scanner.nextInt();
        }
        
        // Define a lambda function to check if all elements in a list are the same
        boolean allSame = (arr) -> {
            for (int i = 0; i < arr.length; i++) {
                if (arr[i]!= arr[0]) {
                    return false;
                }
            }
            return true;
        };
        
        // Check if all elements in the list are the same
        if (allSame.apply(elems)) {
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
        if (!allSame.apply(elems, k-1, n-1)) {
            // If not, print -1 and return
            System.out.println(-1);
            return;
        }
        
        // Set the target to the last element of the list
        int target = elems[n-1];
        
        // Initialize to_delete as elements from the start to k-1
        int[] toDelete = new int[k-1];
        for (int i = 0; i < k-1; i++) {
            toDelete[i] = elems[i];
        }
        
        // Remove elements from to_delete that are equal to target until a different element is found
        int i = k-2;
        while (i >= 0 && toDelete[i] == target) {
            toDelete[i] = 0;
            i--;
        }
        
        // Print the length of to_delete
        int count = 0;
        for (int j = 0; j < k-1; j++) {
            if (toDelete[j]!= 0) {
                count++;
            }
        }
        System.out.println(count);
    }
}

