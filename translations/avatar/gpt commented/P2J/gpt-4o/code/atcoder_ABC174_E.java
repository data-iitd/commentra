import java.util.Scanner;

public class Main {
    // Function to check the condition
    public static boolean check(int[] lis, int k, int mid) {
        for (int i : lis) {
            if (i % mid == 0) {
                k++;
            }
            k -= (i / mid);
        }
        return k >= 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values for n (number of elements) and k (threshold value)
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Read the list of integers
        int[] lis = new int[n];
        for (int i = 0; i < n; i++) {
            lis[i] = scanner.nextInt();
        }

        // Initialize the binary search bounds
        int a = 1, b = Integer.MIN_VALUE;
        for (int num : lis) {
            if (num > b) {
                b = num;
            }
        }
        
        // Set the initial answer to the maximum value in the list
        int ans = b;

        // Perform binary search to find the optimal mid value
        while (a <= b) {
            // Calculate the mid value
            int mid = (a + b) / 2;
            // Check if the current mid value satisfies the condition using the check function
            if (check(lis, k, mid)) {
                // If it does, update the answer and narrow the search to the left half
                ans = mid;
                b = mid - 1;
            } else {
                // If it doesn't, narrow the search to the right half
                a = mid + 1;
            }
        }

        // Print the final answer
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
