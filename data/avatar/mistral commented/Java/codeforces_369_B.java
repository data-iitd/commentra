
import java.util.Arrays; // Importing the Arrays utility class for array manipulation
import java.util.Scanner; // Importing the Scanner class for reading user input

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in); // Creating a new Scanner object to read user input
        
        // Reading input values from the user
        int n = scan.nextInt(); // Reading the number of points n
        int k = scan.nextInt(); // Reading the number of points to be removed k
        int l = scan.nextInt(); // Reading the length l of each segment
        int r = scan.nextInt(); // Reading the radius r of each circle
        int sAll = scan.nextInt(); // Reading the total score before removing points
        int sk = scan.nextInt(); // Reading the score contributed by the k points to be removed

        // Calling the getPoints() method to get the updated scores of all points
        int[] ans = getPoints(n, k, l, r, sAll, sk);

        // Printing the updated scores of all points
        for (int num : ans) {
            System.out.print(num + " "); // Printing each updated score followed by a space
        }

        System.out.println(); // Printing a newline after printing all scores
    }

    public static int[] getPoints(int n, int k, int l, int r, int sAll, int sk) {
        int[] ans = new int[n]; // Initializing an integer array ans of size n to store the updated scores of all points

        // Filling the initial scores of all points with the value l
        Arrays.fill(ans, l);

        // Calculating the remaining score after removing the given k points and segments of length l
        sAll -= sk + (n - k) * l;

        // Removing the score of the given k points
        sk -= k * l;

        // Finding the indices of the points to be increased in the first while loop
        int idx = n - 1;
        while (sk > 0 && idx >= n - k) {
            ans[idx--]++; // Increasing the score of the current point by 1
            sk--; // Decreasing the remaining score by 1
        }

        // Finding the indices of the points to be increased in the second while loop
        while (sAll > 0) {
            idx = 0;
            while (sAll > 0 && idx < n - k) {
                ans[idx++]++; // Increasing the score of the current point by 1
                sAll--; // Decreasing the remaining score by 1
            }
        }

        // Returning the updated scores of all points as an array
        return ans;
    }
}

These comments should provide a clear understanding of the code and its logical flow.