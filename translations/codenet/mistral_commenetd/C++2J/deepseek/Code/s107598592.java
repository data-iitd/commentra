import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Number of elements in the vector

        // Declaring two ArrayList X and Y of size N
        ArrayList<Integer> X = new ArrayList<>();
        ArrayList<Integer> Y = new ArrayList<>();

        // Filling the ArrayList X with user input
        for (int i = 0; i < N; i++) {
            X.add(scanner.nextInt()); // Taking input of X[i] from the user
            Y.add(X.get(i)); // Assigning X[i] to Y[i]
        }

        // Sorting the ArrayList Y in ascending order
        Collections.sort(Y);

        // Finding the middle element of sorted ArrayList Y
        int y = Y.get(N / 2);

        // Iterating through the ArrayList X and printing the middle element of Y based on the condition
        for (int i = 0; i < N; i++) {
            if (X.get(i) < Y.get(N / 2)) { // Checking if X[i] is less than the middle element of Y
                System.out.println(Y.get(N / 2)); // If true, print the middle element of Y
            } else { // If X[i] is greater than or equal to the middle element of Y
                System.out.println(Y.get(N / 2 - 1)); // Print the middle element of Y - 1
                break; // Exit the loop as we have found the required element
            }
        }

        // End of main function
    }
}
