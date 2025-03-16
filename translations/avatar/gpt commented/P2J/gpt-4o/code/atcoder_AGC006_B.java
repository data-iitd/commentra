import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Define a method to perform calculations on the input list
    public static int calc(List<Integer> x) {
        // Define a helper method to process the list y
        return sub(x);
    }

    // Helper method to process the list
    private static int sub(List<Integer> y) {
        // Reduce the list y until it has only one element
        while (y.size() > 1) {
            List<Integer> newY = new ArrayList<>();
            for (int i = 0; i < y.size() - 2; i++) {
                List<Integer> temp = new ArrayList<>(y.subList(i, i + 3));
                Collections.sort(temp);
                newY.add(temp.get(1)); // Add the second largest element
            }
            y = newY; // Update y
        }
        return y.get(0); // Return the final processed value
    }

    public static void main(String[] args) {
        // Read input values N and X from the user
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int X = scanner.nextInt();

        // Check specific conditions based on the value of X
        if (X == 1 || X == N * 2 - 1) {
            // If X is at the boundaries, print "No"
            System.out.println("No");
        } else {
            // If X is within the valid range, print "Yes"
            System.out.println("Yes");

            // Handle the case where X is N * 2 - 2
            if (X == N * 2 - 2) {
                // Create a list xs with specific ranges
                List<Integer> xs = new ArrayList<>();
                for (int i = N - 1; i <= X + 1; i++) {
                    xs.add(i);
                }
                for (int i = 1; i < N - 1; i++) {
                    xs.add(i);
                }
                // Print each element in the final list xs
                for (int x : xs) {
                    System.out.println(x);
                }
            } else {
                // Create a list ys with specific ranges and then construct xs
                List<Integer> ys = new ArrayList<>();
                for (int i = 1; i < X - 1; i++) {
                    ys.add(i);
                }
                for (int i = X + 3; i < N * 2; i++) {
                    ys.add(i);
                }
                List<Integer> xs = new ArrayList<>();
                for (int i = 0; i < Math.max(0, N - 3); i++) {
                    xs.add(ys.get(i));
                }
                xs.add(X + 2);
                xs.add(X - 1);
                xs.add(X);
                xs.add(X + 1);
                for (int i = Math.max(0, N - 3); i < ys.size(); i++) {
                    xs.add(ys.get(i));
                }
                // Print each element in the final list xs
                for (int x : xs) {
                    System.out.println(x);
                }
            }
        }
        scanner.close();
    }
}
// <END-OF-CODE>
