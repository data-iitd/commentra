import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer n from the standard input
        int n = scanner.nextInt();
        
        // Create an array a of size n by reading n integers from the standard input
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Initialize two variables, pre and ans, to Integer.MAX_VALUE and 0, respectively
        int pre = Integer.MAX_VALUE;
        int ans = 0;
        
        // Sort the array a in descending order
        Arrays.sort(a);
        for (int i = 0; i < n / 2; i++) {
            int temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }
        
        // Iterate through the array a
        for (int j = 0; j < n; j++) {
            // Calculate the maximum of 0 and the minimum of pre - 1 and a[j]. This value is added to ans.
            ans += Math.max(0, Math.min(pre - 1, a[j]));
            
            // Update the value of pre to be the minimum of pre - 1 and a[j].
            pre = Math.min(pre - 1, a[j]);
        }
        
        // After the loop, print the value of ans.
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
