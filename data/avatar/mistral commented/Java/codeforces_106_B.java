import java.util.Arrays; // Importing Arrays utility class
import java.util.*; // Importing utility package
import java.io.PrintWriter; // Importing PrintWriter class
import java.util.Scanner; // Importing Scanner class

public class Main {
    // Main method is the entry point of the program
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); // Creating a new Scanner object to read input
        PrintWriter out = new PrintWriter(System.out); // Creating a new PrintWriter object to write output

        int n = input.nextInt(); // Reading the number of items from the input

        int[][] vec = new int[n][4]; // Creating a 2D array of size n x 4 to store the items

        // Initializing the 2D array with input values
        for (int i = 0; i < n; i++) {
            vec[i][0] = input.nextInt(); // Reading the first element of the current item
            vec[i][1] = input.nextInt(); // Reading the second element of the current item
            vec[i][2] = input.nextInt(); // Reading the third element of the current item
            vec[i][3] = input.nextInt(); // Reading the fourth element of the current item
        }

        int ans = 500; // Initializing answer variables with default values
        int ansprice = 20000;

        // Finding the answer by comparing all items and keeping track of the minimum price item found so far
        for (int i = 0; i < n; i++) {
            int flag = 1; // Initializing a flag variable to check if the current item is smaller than all other items

            for (int j = 0; j < n; j++) {
                if (vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2]) {
                    flag = 0; // If the current item is smaller than the other item, set the flag to 0
                    break; // Exit the inner loop as we don't need to check further if the current item is smaller
                }
            }

            if (flag == 1) { // If the current item is not smaller than any other item, check if its price is lower than the current answer
                if (vec[i][3] < ansprice) {
                    ansprice = vec[i][3]; // Update the answer price if the current item's price is lower
                    ans = i + 1; // Update the answer index
                }
            }
        }

        // Printing the answer
        System.out.println(ans);
        out.close();
    }
}
