import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Variable to store the number of elements in the array

        // Allocate memory for the array and read its elements
        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            a.add(scanner.nextInt());
        }

        // Initialize variables
        int idx = 1; // Index for checking the current element in the array
        int ans = 0; // Variable to store the answer

        // Process the array
        for (int i = 0; i < N; i++) {
            // Check if the current element matches the index
            if (a.get(i).equals(idx)) {
                // Increment the index
                idx++;
            } else {
                // Increment the answer
                ans++;
            }
        }

        // Output the result
        if (idx == 1) {
            System.out.println(-1); // Output -1 if all elements are the same
        } else {
            System.out.println(ans); // Output the answer otherwise
        }

        // Terminate the program
        scanner.close();
    }
}
