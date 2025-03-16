
import java.util.*; // Import the necessary libraries for input and output

public class s623008479{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a scanner object to read input from standard input
        int n = sc.nextInt(); // Read the value of n from standard input
        int k = sc.nextInt(); // Read the value of k from standard input
        int[] l = new int[n]; // Create an array of size n to store the elements
        for (int i = 0; i < n; i++) {
            l[i] = sc.nextInt(); // Read each element into the array
        }
        Arrays.sort(l); // Sort the array in ascending order
        int ans = 0; // Initialize a variable to hold the sum of the largest k elements
        for (int i = 0; i < k; i++) {
            ans += l[n - 1 - i]; // Add the largest k elements to ans
        }
        System.out.println(ans); // Output the result
    }
}
