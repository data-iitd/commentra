import java.util.Scanner;
import java.util.Vector;

public class Solution {
    public static void main(String[] args) {
        // Declare variables for the number of people (n) and the number of food items (m)
        int n, m;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt(); // Input the value of n
        m = sc.nextInt(); // Input the value of m

        // Create a vector to count the number of people who like each food item
        Vector<Integer> foods = new Vector<Integer>(m);

        // Loop through each person to gather their food preferences
        for (int i = 0; i < n; i++) {
            int k; // Number of food items the current person likes
            k = sc.nextInt(); // Input the number of food items

            // Loop through each food item liked by the current person
            for (int j = 0; j < k; j++) {
                int temp; // Temporary variable to hold the food item index
                temp = sc.nextInt(); // Input the food item index
                temp--; // Convert to zero-based index

                // Increment the count for the corresponding food item
                foods.set(temp, foods.get(temp) + 1);
            }
        }

        // Initialize a counter for the number of food items liked by all people
        int ans = 0;
        // Loop through the food counts to find how many are liked by all n people
        for (int elem : foods) {
            if (elem == n) { // Check if the food item is liked by all n people
                ans++; // Increment the answer if the condition is met
            }
        }

        // Output the total number of food items liked by all people
        System.out.println(ans);
    }
}

