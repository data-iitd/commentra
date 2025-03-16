import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Ask the user for the number of elements in the list
        int n = scanner.nextInt();

        // Initialize a list to store the integers
        List<Integer> l = new ArrayList<>();

        // Iterate n times and append each integer to the list
        for (int i = 0; i < n; i++) {
            // Ask the user for the next integer and append it to the list
            l.add(scanner.nextInt());
        }

        // Initialize a variable to store the answer
        int ans = n - 1;

        // Initialize a variable to store the previous integer in the list
        int last = 0;

        // Iterate through each integer in the list
        for (int i : l) {
            // Calculate the absolute difference between the previous integer and the current integer
            // Add 1 to account for the number of steps between the two integers
            ans += Math.abs(last - i) + 1;

            // Update the value of the previous integer
            last = i;
        }

        // Print the value of the answer
        System.out.println(ans);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
