import java.util.Arrays;
import java.util.Scanner;

public class Main {
    // Define the arm class to hold the left and right positions
    static class Arm {
        int l, r;

        Arm(int l, int r) {
            this.l = l;
            this.r = r;
        }
    }

    public static void main(String[] args) {
        // Initialize scanner
        Scanner sc = new Scanner(System.in);

        // Read the number of arms, n
        int n = sc.nextInt();

        // Initialize an array of arm structures
        Arm[] arms = new Arm[n];

        // Read and initialize each arm structure in the array
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int l = sc.nextInt();

            // Initialize the left and right fields of the arm structure
            arms[i] = new Arm(x - l, x + l);
        }

        // Sort the array based on the right field of the arm structures
        Arrays.sort(arms, (a, b) -> Integer.compare(a.r, b.r));

        // Initialize answer variable, ans, and right variable, r
        int ans = 1;
        int r = arms[0].r;

        // Iterate through the array and update the answer and right variable accordingly
        for (int i = 1; i < n; i++) {
            if (arms[i].l >= r) { // Check if the left end of the current arm is greater than or equal to the right end of the previous arm
                ans++; // Increment the answer if it is
                r = arms[i].r; // Update the right variable with the right end of the current arm
            }
        }

        // Print the answer
        System.out.println(ans);

        // Close the scanner
        sc.close();
    }
}

// <END-OF-CODE>
