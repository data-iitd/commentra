import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a Scanner object for reading input
        Scanner scanner = new Scanner(System.in);

        // Start an infinite loop to read input values until EOF is reached
        while (scanner.hasNextInt()) {
            // Declare an integer array 'c' of size 3 to store the input values
            int[] c = new int[3];

            // Read three integers into the array 'c'
            for (int i = 0; i < 3; i++) {
                c[i] = scanner.nextInt();
            }

            // Declare and initialize a boolean array 'card' of size 10
            boolean[] card = new boolean[10];
            int count = 0;
            int sum = c[0] + c[1]; // Initialize sum with the sum of the first two input values

            // Loop through the array 'c' to mark the corresponding index in 'card' array
            for (int i = 0; i < 3; i++) {
                card[c[i] - 1] = true; // Set the index in 'card' array to true if the corresponding value in 'c' is read
            }

            // Loop through the array 'card' to check if there are at least 4 distinct numbers in the input
            for (int i = 0; i < 10; i++) {
                // If the index in 'card' array is not set to true and the sum of input values, index and 1 is less than or equal to 20
                if (!card[i] && sum + i + 1 <= 20) {
                    count++; // Increment the count if the condition is true
                }
            }

            // Check if the count is greater than or equal to 4 and print "YES" if true, otherwise print "NO"
            if (count >= 4) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
