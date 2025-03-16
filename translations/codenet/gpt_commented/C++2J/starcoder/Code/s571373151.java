import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Declare variables for the number of people (n) and the number of food items (m)
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        // Create a vector to count the number of people who like each food item
        int[] foods = new int[m];

        // Loop through each person to gather their food preferences
        for (int i = 0; i < n; i++) {
            int k = sc.nextInt(); // Number of food items the current person likes

            // Loop through each food item liked by the current person
            for (int j = 0; j < k; j++) {
                int temp = sc.nextInt(); // Temporary variable to hold the food item index
                temp--; // Convert to zero-based index

                // Increment the count for the corresponding food item
                foods[temp]++;
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

