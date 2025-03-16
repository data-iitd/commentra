
import java.util.Scanner;

public class s526060174{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // 1. Input Reading: Declare variables to store the number of sets and the maximum element value.
        int m = sc.nextInt();
        int[] x = new int[31]; // 2. Array Initialization: Initialize an array to count occurrences of each element from 1 to 30.
        for (int i = 0; i < n; ++i) { // 3. Nested Loops for Input: Loop through each set.
            int k = sc.nextInt(); // Read the number of elements in the current set.
            for (int j = 0; j < k; ++j) { // Loop through each element in the current set.
                int a = sc.nextInt(); // Read an element.
                x[a]++; // Increment the count of the element in the array x.
            }
        }
        int ans = 0; // 4. Counting Elements: Initialize a variable to store the count of elements that appear in every set.
        for (int i = 1; i <= m; ++i) { // Loop through each element from 1 to m.
            if (x[i] == n) { // Check if the element appears in every set.
                ans++; // Increment the count if the condition is met.
            }
        }
        System.out.println(ans); // 5. Output the Result: Print the final count of elements that appear in every set.
        sc.close();
    }
}
