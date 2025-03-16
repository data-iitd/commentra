import java.util.Scanner; // Importing the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input
        int n = sc.nextInt(); // Reading the number of ingredients
        int m = sc.nextInt(); // Reading the number of nutrient types
        int x = sc.nextInt(); // Reading the minimum requirement for each nutrient
        int min = Integer.MAX_VALUE; // Initializing the minimum cost to a large value
        int[][] a = new int[n][m + 1]; // Initializing the 2D array to store nutrient amounts

        // Filling the array with nutrient amounts for each ingredient
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        // Generating all possible combinations of ingredients
        for (int i = 0; i < Math.pow(2, n); i++) {
            int[] status = new int[n]; // Array to store the status of each ingredient in the combination
            for (int j = 0; j < n; j++) {
                if ((1 & i >> j) == 1) { // Checking if the j-th ingredient is included
                    status[j] = 1;
                }
            }
            int[] res = new int[m + 1]; // Array to store the total nutrient amounts for the current combination
            for (int j = 0; j < n; j++) {
                if (status[j] == 1) { // Adding the nutrient amounts of included ingredients
                    for (int k = 0; k <= m; k++) {
                        res[k] += a[j][k];
                    }
                }
            }
            boolean flag = true; // Flag to check if the current combination meets the requirement
            for (int j = 1; j <= m; j++) {
                if (res[j] < x) { // Checking if the nutrient requirement is met
                    flag = false;
                    break;
                }
            }
            if (flag) {
                min = Math.min(min, res[0]); // Updating the minimum cost if the requirement is met
            }
        }

        // Outputting the result
        if (min == Integer.MAX_VALUE) {
            System.out.println(-1); // Outputting -1 if no combination meets the requirement
        } else {
            System.out.println(min); // Outputting the minimum cost if a valid combination is found
        }
    }
}
