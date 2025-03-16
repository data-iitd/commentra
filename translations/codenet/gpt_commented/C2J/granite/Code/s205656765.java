
import java.util.Scanner;

public class s205656765{
    public static void main(String[] args) {
        // Declare variables for the number of coins of each type and the target value
        int X, A, B, C;
        int i = 0;
        int j = 0;
        int k = 0;
        int kosu = 0; // Counter for the number of combinations that meet the target value

        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);

        // Input the number of coins of each type and the target value
        A = sc.nextInt(); // Number of 10 yen coins
        B = sc.nextInt(); // Number of 2 yen coins
        C = sc.nextInt(); // Number of 1 yen coins
        X = sc.nextInt(); // Target value in yen

        // Convert the target value from yen to the number of 50 yen coins
        X = X / 50;

        // Iterate through all possible combinations of coins
        for(i = 0; i <= A; i++) { // Loop through the number of 10 yen coins
            for(j = 0; j <= B; j++) { // Loop through the number of 2 yen coins
                for(k = 0; k <= C; k++) { // Loop through the number of 1 yen coins
                    // Check if the current combination of coins equals the target value
                    if(X == (10 * i) + (2 * j) + k) 
                        kosu++; // Increment the counter if the combination matches
                }
            }
        }

        // Output the total number of combinations that meet the target value
        System.out.println(kosu);

        // Close the Scanner object
        sc.close();
    }
}
