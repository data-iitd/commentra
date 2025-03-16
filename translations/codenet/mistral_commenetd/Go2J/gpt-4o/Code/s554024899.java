import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Initialize a new scanner object

        // Read the first two integers from the standard input using the scanner
        int x = sc.nextInt();
        int y = sc.nextInt();

        // Initialize two variables xt and yt to store the indices of the arrays a where x and y are present
        int xt = -1, yt = -1;

        // Define a 3x3 2D array a
        int[][] a = {
            {1, 3, 5, 7, 8, 10, 12},
            {4, 6, 9, 11},
            {2}
        };

        // Iterate through each inner array of the outer array
        for (int i = 0; i < a.length; i++) {
            // Iterate through each element of the current inner array
            for (int n : a[i]) {
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

        sc.close(); // Close the scanner
    }
}

// <END-OF-CODE>
