// Importing necessary Java utility classes
import java.util.Scanner;  // For reading input from the console
import java.util.Comparator;  // For sorting the list of thetas
import java.util.Arrays;  // For initializing the array of thetas with zeroes
import java.util.List;  // For creating and manipulating lists
import java.util.ArrayList;  // For creating and manipulating ArrayLists

// Main method where the program starts
public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object for reading input from the console
        Scanner scan = new Scanner(System.in);

        // Reading the number of points (N) from the input
        int N = scan.nextInt();

        // Creating two arrays, x and y, of size N for storing the x and y coordinates of the points respectively
        int[] x = new int[N];
        int[] y = new int[N];

        // Reading the x and y coordinates of each point and storing them in the respective arrays
        for (int i = 0; i < N; ++i) {
            x[i] = scan.nextInt();  // Reading the x coordinate
            y[i] = scan.nextInt();  // Reading the y coordinate
        }

        // Calculating the angles between each pair of points and storing them in a list called thetas
        for (int i = 0; i < N; ++i) {
            List<Double> thetas = new ArrayList<>();  // Creating a new ArrayList for storing the angles

            // Calculating the angles between the current point and all other points
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;  // Skip if the current point is the same as the other point

                // Calculating the angle using the atan2 function
                thetas.add(Math.atan2(y[j] - y[i], x[j] - x[i]));
            }

            // Sorting the list of angles in ascending order
            thetas.sort(Comparator.naturalOrder());

            // Adding the angle between the last point and the first point (wrapped around 2π) to the list
            thetas.add(thetas.get(0) + 2 * Math.PI);
        }

        // Finding the maximum angle between consecutive angles and calculating the answer
        double ans = 0;
        for (int k = 0; k < N - 1; ++k) {
            ans = Math.max(ans, thetas.get(k + 1) - thetas.get(k) - Math.PI);
        }

        // Printing the answer
        System.out.println(ans / (Math.PI * 2));
    }
}
