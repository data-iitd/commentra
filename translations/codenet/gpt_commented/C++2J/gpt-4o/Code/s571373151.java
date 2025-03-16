import java.util.Scanner;

public class FoodPreferences {
    public static void main(String[] args) {
        // Declare variables for the number of people (n) and the number of food items (m)
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Input the number of people
        int m = scanner.nextInt(); // Input the number of food items

        // Create an array to count the number of people who like each food item
        int[] foods = new int[m];

        // Loop through each person to gather their food preferences
        for (int i = 0; i < n; i++) {
            int k = scanner.nextInt(); // Number of food items the current person likes

            // Loop through each food item liked by the current person
            for (int j = 0; j < k; j++) {
                int temp = scanner.nextInt(); // Input the food item index
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
        scanner.close();
    }
}
// <END-OF-CODE>
