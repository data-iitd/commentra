import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements (n) and the initial value (x) from input
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        
        // Read and sort the list of integers
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        Arrays.sort(a);
        
        // Initialize the answer counter
        int ans = 0;
        
        // Check if the smallest element in the sorted list is greater than x
        if (a[0] > x) {
            // If true, print 0 and exit since no elements can be subtracted from x
            System.out.println(0);
            return;
        }
        
        // Iterate through the sorted list of integers
        for (int i : a) {
            // If the current element is greater than x, set x to 0 and break the loop
            if (i > x) {
                x = 0;
                break;
            }
            // Subtract the current element from x
            x -= i;
            // Increment the answer counter
            ans += 1;
        }
        
        // If there is any remaining value in x, decrement the answer counter
        if (x != 0) {
            ans -= 1;
        }
        
        // Print the final answer
        System.out.println(ans);
    }
}
