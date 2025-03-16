import java.util.Scanner;

public class Main {
    static final int MAXN = 100010; // Define the maximum size for arrays

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n, m, Q; // Declare variables for the size of arrays and number of queries
        n = scanner.nextInt();
        m = scanner.nextInt();
        Q = scanner.nextInt();
        
        int[] a = new int[MAXN]; // Declare array a to store the input elements
        int[] b = new int[MAXN], id = new int[MAXN]; // Declare arrays b and id for storing unique elements and their positions
        boolean[] vis = new boolean[MAXN]; // Declare a boolean array vis to mark processed elements
        int[] cnt = new int[MAXN]; // Declare an array cnt to count elements in each position

        for (int i = 1; i <= Q; ++i) {
            a[i] = scanner.nextInt(); // Read the elements of array a
        }

        int k = 0;
        for (int j = Q; j > 0; --j) { // Process the elements of array a
            if (!vis[a[j]]) { // If the element has not been processed
                b[++k] = a[j];
                vis[a[j]] = true; // Mark it as processed
            }
        }

        for (int i = m, j = m; i > 0; --i) { // Fill the remaining positions in b
            if (!vis[i]) {
                b[j--] = i;
            }
        }

        for (int i = 1; i <= m; ++i) {
            id[b[i]] = i; // Store the position of each element in b
        }

        boolean flag = true; // Initialize flag to true
        cnt[0] = n; // Initialize the count of elements in the first position
        for (int i = Q; i > 0; --i) { // Iterate through the elements of array a in reverse order
            int t = id[a[i]]; // Get the position of the current element in b
            if (cnt[t - 1] > 0) { // If there is a position available one less than the current position
                --cnt[t - 1]; // Decrease the count of the previous position
                ++cnt[t]; // Increase the count of the current position
                vis[t] = true; // Mark the current position as processed
            } else if (!vis[t]) { // If the current position is not available and not yet marked as processed
                flag = false; // Set flag to false
                break; // Break out of the loop
            }
        }

        int l; // Declare variable l to find the smallest non-zero count
        for (l = 0; cnt[l] == 0; ++l); // Find the smallest index l with a non-zero count
        for (int i = l + 1; i < m; ++i) { // Check if the elements in b are in strictly increasing order
            flag &= b[i] < b[i + 1];
        }

        System.out.println(flag ? "Yes" : "No"); // Print "Yes" if the conditions are met, otherwise print "No"
        scanner.close();
    }
}
// <END-OF-CODE>
