import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        // Read the first two integers from the standard input
        String[] input = reader.readLine().split(" ");
        int x = Integer.parseInt(input[0]);
        int y = Integer.parseInt(input[1]);

        // Initialize two variables xt and yt to store the indices of the arrays a where x and y are present
        int xt = -1, yt = -1;

        // Define a 3x3 2D array a
        List<List<Integer>> a = new ArrayList<>();
        a.add(List.of(1, 3, 5, 7, 8, 10, 12));
        a.add(List.of(4, 6, 9, 11));
        a.add(List.of(2));

        // Iterate through each inner loop of the outer loop
        for (int i = 0; i < a.size(); i++) {
            // Iterate through each element of the current inner loop
            for (int n : a.get(i)) {
                // Check if the current element is equal to x, if yes, store its index in xt
                if (x == n) {
                    xt = i;
                }
                // Check if the current element is equal to y, if yes, store its index in yt
                if (y == n) {
                    yt = i;
                }
            }
        }

        // Check if the indices xt and yt are equal, if yes, print "Yes"
        if (xt == yt) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
