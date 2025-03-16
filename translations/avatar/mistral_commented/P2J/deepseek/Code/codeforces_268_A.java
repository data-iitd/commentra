import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ask user for the number of arrays (n) they want to input
        int n = Integer.parseInt(scanner.nextLine());

        // Create an empty list called 'q' to store these arrays
        List<String[]> q = new ArrayList<>();

        // Use a for loop to iterate through the range of 'n' and for each iteration,
        // ask the user for an array (a) and append it to our list 'q'
        for (int i = 0; i < n; i++) {
            // Ask user for an array (a)
            String[] a = scanner.nextLine().split(" ");
            // Append array 'a' to our list 'q'
            q.add(a);
        }

        // Initialize a count variable to keep track of matches
        int count = 0;

        // Use another for loop to iterate through each array in our list 'q'
        for (int j = 0; j < q.size(); j++) {
            // For each array 'j', use another for loop to iterate through every other array in our list 'q'
            for (int k = 0; k < q.size(); k++) {
                // Exclude the current array 'j' from comparison using 'continue' statement if they are the same
                if (j == k) {
                    continue;
                }
                // Check if the last element of the second array 'k' matches the first element of the first array 'j'
                if (q.get(j)[0].equals(q.get(k)[q.get(k).length - 1])) {
                    // If it does, increment our 'count' variable
                    count++;
                }
            }
        }

        // Finally, print out the value of our 'count' variable
        System.out.println(count);
    }
}
