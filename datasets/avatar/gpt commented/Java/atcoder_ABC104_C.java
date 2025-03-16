import java.util.Scanner;

public class Main {
    // Define a constant for infinity (a large number)
    static final int INF = 100000;

    public static void main(String[] args) {
        // Create a Scanner object for input
        Scanner sc = new Scanner(System.in);

        // Read the number of problems D and the goal score G
        int D = sc.nextInt();
        long G = sc.nextLong();

        // Arrays to store the number of problems and their corresponding scores
        int[] p = new int[D]; // p[i] = number of problems for the i-th problem set
        int[] c = new int[D]; // c[i] = additional score for the i-th problem set

        // Read the number of problems and additional scores for each problem set
        for (int i = 0; i < D; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }

        // Initialize the minimum number of problems solved to infinity
        int min = INF;

        // Iterate through all possible combinations of problem sets using bit masking
        for (int bit = 0; bit < (1 << D); bit++) {
            int score = 0; // Total score achieved with the current combination
            int solve_num = 0; // Total number of problems solved with the current combination

            // Calculate the score and number of problems solved for the current combination
            for (int i = 0; i < D; i++) {
                if ((bit & (1 << i)) != 0) { // Check if the i-th problem set is included
                    score += 100 * (i + 1) * p[i] + c[i]; // Update score
                    solve_num += p[i]; // Update number of problems solved
                }
            }

            // If the current score is less than the goal score G
            if (score < G) {
                loop: // Label for breaking out of the nested loop
                for (int i = D - 1; i >= 0; i--) { // Iterate through problem sets in reverse
                    if ((bit & (1 << i)) == 0) { // Check if the i-th problem set is not included
                        // Attempt to solve additional problems from this set
                        for (int j = 0; j < p[i] - 1; j++) {
                            score += 100 * (i + 1); // Increase score by the value of the problem
                            solve_num++; // Increment the number of problems solved
                            if (score >= G) { // If the score meets or exceeds the goal
                                break loop; // Exit the loop
                            }
                        }
                    }
                }
            }

            // If the score meets or exceeds the goal, update the minimum number of problems solved
            if (score >= G) {
                min = Math.min(min, solve_num); // Update min if a better solution is found
            }
        }

        // Output the minimum number of problems solved to achieve the goal score
        System.out.println(min);

        // Close the scanner to free resources
        sc.close();
    }
}
