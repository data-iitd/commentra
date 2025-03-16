public class Main {
    public static void main(String[] args) {
        // Declare variables
        int n, m;
        int[] foods;

        // Read input values
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();

        // Initialize a vector of size m to store the count of each food item
        foods = new int[m];

        // Read n food preferences from the standard input
        for (int i = 0; i < n; i++) {
            int k;

            // Read the number of food items in the current preference
            k = scanner.nextInt();

            // Read the indices of the food items in the current preference
            for (int j = 0; j < k; j++) {
                int temp;

                // Read the index of the current food item
                temp = scanner.nextInt();

                // Increment the count of the corresponding food item in the foods vector
                foods[temp]++;
            }
        }

        // Initialize a variable to store the number of food items that appear in all preferences
        int ans = 0;

        // Iterate through each element in the foods vector and check if its count is equal to the total number of preferences
        for (int elem : foods) {
            if (elem == n) {
                ans++;
            }
        }

        // Print the value of ans to the standard output
        System.out.println(ans);
    }
}
