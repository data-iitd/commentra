import java.util.Scanner;

public class FoodPreferences {
    public static void main(String[] args) {
        // Declare variables
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initialize an array to store the count of each food item
        int[] foods = new int[m];

        // Read n food preferences from the standard input
        for (int i = 0; i < n; i++) {
            int k = scanner.nextInt();

            // Read the indices of the food items in the current preference
            for (int j = 0; j < k; j++) {
                int temp = scanner.nextInt();

                // Increment the count of the corresponding food item in the foods array
                foods[temp]++;
            }
        }

        // Initialize a variable to store the number of food items that appear in all preferences
        int ans = 0;

        // Iterate through each element in the foods array and check if its count is equal to the total number of preferences
        for (int elem : foods) {
            if (elem == n) {
                ans++;
            }
        }

        // Print the value of ans to the standard output
        System.out.println(ans);
        
        scanner.close();
    }
}
// <END-OF-CODE>
