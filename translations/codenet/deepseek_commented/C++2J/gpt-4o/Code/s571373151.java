import java.util.Scanner;

public class FoodPreferences {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(); // Read the number of people
        int m = scanner.nextInt(); // Read the number of food types

        int[] foods = new int[m]; // Initialize an array to keep track of food counts

        for (int i = 0; i < n; i++) { // Loop through each person
            int k = scanner.nextInt(); // Read the number of food preferences for this person

            for (int j = 0; j < k; j++) { // Loop through each food preference
                int temp = scanner.nextInt(); // Read the type of food
                temp--; // Adjust the food type to be 0-indexed

                foods[temp]++; // Increment the count of this food type
            }
        }

        int ans = 0; // Initialize a counter for food types preferred by all people

        for (int elem : foods) { // Loop through each food type count
            if (elem == n) { // Check if the food type is preferred by all people
                ans++; // Increment the counter
            }
        }

        System.out.println(ans); // Output the number of food types preferred by all people
        scanner.close();
    }
}

// <END-OF-CODE>
