
import java.util.*;

public class Main {

    public static void main(String[] args) {

        // Take the number of elements in the array as input
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Initialize an empty list 'arr' of size 'n' and fill it with integers taken as input
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Initialize an empty list 'ans' of size 'n' with zeros
        int[] ans = new int[n];

        // Variable'mx' stores the maximum element in the array
        int mx = arr[n - 1];

        // Iterate through the array from index 'n-2' to '0' in reverse order
        for (int i = n - 2; i >= 0; i--) {

            // Update the answer at current index 'i' based on the maximum element'mx' and current element 'arr[i]'
            ans[i] = Math.max(0, mx - arr[i] + 1);

            // If the current element 'arr[i]' is greater than the maximum element'mx', update'mx'
            if (arr[i] > mx) {
                mx = arr[i];
            }
        }

        // Print the answer list
        for (int i = 0; i < n; i++) {
            System.out.print(ans[i] + " ");
        }
    }
}

