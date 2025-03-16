import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Step 1: Reading the number of elements (n)
        int n = scanner.nextInt();

        // Step 2: Reading the list of elements (a)
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Step 3: Initializing variables
        int pre = Integer.MAX_VALUE;  // Initialize pre to infinity
        int ans = 0;  // Initialize ans to 0

        // Step 4: Sorting the list in descending order
        Arrays.sort(a);
        for (int i = 0; i < n / 2; i++) {
            int temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }

        // Step 5: Iterating through the list
        for (int j = 0; j < n; j++) {
            // Calculate the maximum value that can be added to ans
            ans += Math.max(0, Math.min(pre - 1, a[j]));
            // Update pre to be the maximum of 0 and the minimum of pre - 1 and the current element
            pre = Math.max(0, Math.min(pre - 1, a[j]));
        }

        // Step 6: Printing the result
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
