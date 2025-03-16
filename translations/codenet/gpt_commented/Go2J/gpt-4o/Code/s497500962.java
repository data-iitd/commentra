import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the values for R, G, B, and N from standard input
        int R = nextInt(sc); // Number of red items
        int G = nextInt(sc); // Number of green items
        int B = nextInt(sc); // Number of blue items
        int N = nextInt(sc); // Total number of items to choose

        int ans = 0; // Variable to store the count of valid combinations

        // Iterate over possible counts of red items (x)
        for (int x = 0; x <= N; x++) {
            // Iterate over possible counts of green items (y)
            for (int y = 0; y <= N; y++) {
                // Calculate the remaining items after choosing x red and y green
                int tmp = N - R * x - G * y;
                // Check if the remaining items can be fully represented by blue items
                if (tmp >= 0 && tmp % B == 0) {
                    ans++; // Increment the count of valid combinations
                }
            }
        }

        // Output the total count of valid combinations
        System.out.println(ans);
    }

    // Function to read the next integer from input
    private static int nextInt(Scanner sc) {
        return sc.nextInt(); // Read and return the next integer
    }
}

// <END-OF-CODE>
