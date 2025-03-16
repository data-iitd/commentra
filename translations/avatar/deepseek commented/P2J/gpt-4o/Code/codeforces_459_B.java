import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Step 1: Take an integer input `n` which represents the number of elements in the list `l1`.
        int n = scanner.nextInt();
        
        // Step 2: Take a space-separated string of integers, convert them into a list of integers, and store it in `l1`.
        int[] l1 = new int[n];
        for (int i = 0; i < n; i++) {
            l1[i] = scanner.nextInt();
        }
        
        // Step 3: Sort the list `l1` in ascending order.
        Arrays.sort(l1);
        
        // Step 4: Assign the last element of the sorted list `l1` to `a`, which is the maximum value in the list.
        int a = l1[n - 1];
        
        // Step 5: Assign the first element of the sorted list `l1` to `b`, which is the minimum value in the list.
        int b = l1[0];
        
        // Step 6: Check if `a` is equal to `b`.
        if (a == b) {
            // Step 7: If `a` is equal to `b`, print the difference `a - b` and the number of ways to choose 2 elements from `n` elements.
            System.out.println(a - b + " " + (n * (n - 1) / 2));
        } else {
            // Step 8: If `a` is not equal to `b`, calculate the count of occurrences of `a` and `b` in the list `l1`.
            int ac = 0, bc = 0;
            for (int num : l1) {
                if (num == a) ac++;
                if (num == b) bc++;
            }
            // Step 9: Print the difference `a - b` and the product of the counts of `a` and `b`.
            System.out.println(a - b + " " + (ac * bc));
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
