import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Initialize the answer variable to store the result
        int ans = 0;
        // Create a Scanner object for reading input
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements in the list
        int n = sc.nextInt();
        // Initialize an array to hold the input numbers
        int list[] = new int[n];
        
        // Populate the list array with input values
        for (int i = 0; i < n; i++) {
            list[i] = sc.nextInt();
        }
        
        // Initialize two arrays to count occurrences of numbers
        int numlist1[] = new int[100000];
        int numlist2[] = new int[100000];
        
        // Set all counts in numlist1 and numlist2 to zero
        for (int i = 0; i < 100000; i++) {
            numlist1[i] = 0;
            numlist2[i] = 0;
        }
        
        // Count occurrences of numbers at even and odd indices separately
        for (int i = 0; i < n; i += 2) {
            numlist1[list[i] - 1] += 1; // Count for even indexed elements
            numlist2[list[i + 1] - 1] += 1; // Count for odd indexed elements
        }
        
        // Initialize variables to track the two most frequent elements
        int max11 = 0, max12 = 0, max21 = 0, max22 = 0;
        int val1 = 0, val2 = 0;
        
        // Determine the two most frequent elements in each list
        for (int i = 0; i < 100000; i++) {
            // Update max11 and max12 for numlist1
            if (numlist1[i] >= max11) {
                max12 = max11;
                max11 = numlist1[i];
                val1 = i; // Store the value of the most frequent element
            } else if (numlist1[i] >= max12) {
                max12 = numlist1[i];
            }
            // Update max21 and max22 for numlist2
            if (numlist2[i] >= max21) {
                max22 = max21;
                max21 = numlist2[i];
                val2 = i; // Store the value of the most frequent element
            } else if (numlist2[i] >= max22) {
                max22 = numlist2[i];
            }
        }
        
        // Calculate the answer based on the most frequent elements
        if (val1 != val2) {
            // If the most frequent elements are different, calculate directly
            ans = n - max11 - max21;
        } else {
            // If the most frequent elements are the same, take the maximum of alternatives
            ans = n - Math.max(max12 + max21, max11 + max22);
        }
        
        // Output the final answer
        System.out.println(ans);
    }
}
