import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a scanner to read input
        Scanner sc = new Scanner(System.in);

        // Read two integers from input
        int x = sc.nextInt();
        int y = sc.nextInt();

        // Initialize variables to store the category indices of x and y
        int xt = -1, yt = -1;

        // Define a 2D array where each sub-array represents a category of numbers
        int[][] a = {
            {1, 3, 5, 7, 8, 10, 12},
            {4, 6, 9, 11},
            {2}
        };

        // Iterate through the categories to find the indices of x and y
        for (int i = 0; i < a.length; i++) {
            for (int n : a[i]) {
                // Check if the current number matches x
                if (x == n) {
                    xt = i; // Store the category index for x
                }
                // Check if the current number matches y
                if (y == n) {
                    yt = i; // Store the category index for y
                }
            }
        }

        // Compare the category indices of x and y and print the result
        if (xt == yt) {
            System.out.println("Yes"); // x and y belong to the same category
        } else {
            System.out.println("No");  // x and y belong to different categories
        }

        sc.close(); // Close the scanner
    }
}

// max function is not needed in this context

// <END-OF-CODE>
