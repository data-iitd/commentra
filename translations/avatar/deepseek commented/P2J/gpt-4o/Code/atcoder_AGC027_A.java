import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read n and x from input
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        
        // Read the list a from input
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Sort the array a in ascending order
        Arrays.sort(a);
        
        int ans = 0; // Initialize the variable ans to store the result
        
        if (a[0] > x) {
            System.out.println(0);
            return; // Check if the smallest element in the sorted list a is greater than x
        }
        
        for (int i : a) {
            if (i > x) {
                x = 0;
                break; // If an element greater than x is encountered, set x to 0 and break
            }
            x -= i; // Subtract the element from x
            ans++; // Increment ans
        }
        
        if (x != 0) {
            ans--; // If x is not 0 after the loop, decrement ans by 1
        }
        
        System.out.println(ans); // Print the value of ans
    }
}
// <END-OF-CODE>
