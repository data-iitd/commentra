import java.util.*; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object to read input
        int N = sc.nextInt(); // Read the number of elements N
        long M = sc.nextLong(); // Read the number of comparisons M
        
        long[] H = new long[N]; // Initialize an array to store the heights of N elements
        boolean[] ans = new boolean[N]; // Initialize a boolean array to store the result for each element
        
        // Read the heights of the elements into the array H
        for (int i = 0; i < N; i++) {
            H[i] = sc.nextLong();
            ans[i] = true; // Initialize all elements in the boolean array ans to true
        }
        
        // Read the pairs of indices (temp1 and temp2) and compare the heights at these indices
        for (int i = 0; i < M; i++) {
            int temp1 = sc.nextInt();
            int temp2 = sc.nextInt();
            
            if (H[temp1 - 1] < H[temp2 - 1]) {
                ans[temp1 - 1] = false; // Update the boolean array ans based on the comparison results
            } else if (H[temp1 - 1] > H[temp2 - 1]) {
                ans[temp2 - 1] = false; // Update the boolean array ans based on the comparison results
            } else {
                ans[temp1 - 1] = false; // Update the boolean array ans based on the comparison results
                ans[temp2 - 1] = false; // Update the boolean array ans based on the comparison results
            }
        }
        
        int ans2 = 0; // Initialize a counter to count the number of elements in the boolean array ans that are still true
        // Count the number of elements in the boolean array ans that are still true
        for (int i = 0; i < N; i++) {
            if (ans[i]) {
                ans2++; // Increment the counter if the element is still true
            }
        }
        
        System.out.println(ans2); // Print the count
    }
}
