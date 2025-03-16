

import java.util.Scanner; // Importing the 'Scanner' class for input/output operations

public class s141561537{
    public static void main(String[] args) {
        // Declaring variables a, b, c, x, and sum of integer data type
        int a, b, c, x, sum = 0;

        // Creating a new instance of the 'Scanner' class to read input values from the user
        Scanner scanner = new Scanner(System.in);

        // Reading input values for variables a, b, c, and x from the user
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        x = scanner.nextInt();

        // Initializing a nested for loop to iterate through the possible combinations of i, j, and k
        for (int i = 0; i <= a; i++) { // for i from 0 to a
            for (int j = 0; j <= b; j++) { // for j from 0 to b
                for (int k = 0; k <= c; k++) { // for k from 0 to c
                    // Checking if the sum of i, j, and k multiplied by 50, 100, and 50 respectively equals x
                    if (500 * i + 100 * j + 50 * k == x) {
                        sum++; // Incrementing the sum variable if the condition is true
                    }
                }
            }
        }

        // Printing the final value of sum to the console
        System.out.println(sum);

        // End of the code
    }
}

