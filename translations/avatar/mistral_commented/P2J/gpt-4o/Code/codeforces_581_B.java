import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Take the number of elements in the array as input
        int n = scanner.nextInt();

        // Initialize an array 'arr' of size 'n' and fill it with integers taken as input
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        // Initialize an array 'ans' of size 'n' with zeros
        int[] ans = new int[n];

        // Variable 'mx' stores the maximum element in the array
        int mx = arr[n - 1];

        // Iterate through the array from index 'n-2' to '0' in reverse order
        for (int i = n - 2; i >= 0; i--) {
            // Update the answer at current index 'i' based on the maximum element 'mx' and current element 'arr[i]'
            ans[i] = Math.max(0, mx - arr[i] + 1);

            // If the current element 'arr[i]' is greater than the maximum element 'mx', update 'mx'
            if (arr[i] > mx) {
                mx = arr[i];
            }
        }

        // Print the answer array
        for (int i = 0; i < n; i++) {
            System.out.print(ans[i] + " ");
        }
        System.out.println();

        scanner.close();
    }
}
// <END-OF-CODE>
