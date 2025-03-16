
import java.util.Scanner;

public class s571373151{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Number of people
        int m = scanner.nextInt(); // Number of food items

        int[] foods = new int[m]; // Create an array to count the number of people who like each food item

        // Loop through each person to gather their food preferences
        for (int i = 0; i < n; i++) {
            int k = scanner.nextInt(); // Number of food items the current person likes

            // Loop through each food item liked by the current person
            for (int j = 0; j < k; j++) {
                int temp = scanner.nextInt() - 1; // Temporary variable to hold the food item index

                // Increment the count for the corresponding food item
                foods[temp]++;
            }
        }

        int ans = 0; // Initialize a counter for the number of food items liked by all people
        // Loop through the food counts to find how many are liked by all n people
        for (int elem : foods) {
            if (elem == n) { // Check if the food item is liked by all n people
                ans++; // Increment the answer if the condition is met
            }
        }

        // Output the total number of food items liked by all people
        System.out.println(ans); // Print the answer
    }
}
