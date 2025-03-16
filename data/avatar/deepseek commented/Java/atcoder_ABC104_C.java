import java.util.Scanner; // Importing the Scanner class for input operations

public class Main {
    static final int INF = 100000; // Defining a constant for infinity

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Initializing a Scanner object to read input
        int D = sc.nextInt(); // Reading the number of problems
        long G = sc.nextLong(); // Reading the target score
        int[] p = new int[D]; // Array to store the number of problems completed
        int[] c = new int[D]; // Array to store the bonus points for each problem

        // Reading the number of problems completed and the bonus points for each problem
        for (int i = 0; i < D; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }

        int min = INF; // Initializing the minimum number of problems solved to a large value

        // Using bitmask to iterate through all possible combinations of problem completions
        for (int bit = 0; bit < (1 << D); bit++) {
            int score = 0; // Initializing the current score
            int solve_num = 0; // Initializing the number of problems solved

            // Calculating the total score and the number of problems solved for the current combination
            for (int i = 0; i < D; i++) {
                if ((bit & (1 << i)) != 0) {
                    score += 100 * (i + 1) * p[i] + c[i];
                    solve_num += p[i];
                }
            }

            // If the score is less than the target, try to maximize the score by completing remaining problems
            if (score < G) {
                for (int i = D - 1; i >= 0; i--) {
                    if ((bit & (1 << i)) == 0) {
                        for (int j = 0; j < p[i] - 1; j++) {
                            score += 100 * (i + 1);
                            solve_num++;
                            if (score >= G) {
                                break;
                            }
                        }
                    }
                }
            }

            // Updating the minimum number of problems solved if the current combination meets or exceeds the target score
            if (score >= G) {
                min = Math.min(min, solve_num);
            }
        }

        // Output the minimum number of problems solved to achieve the target score
        System.out.println(min);
        sc.close(); // Closing the Scanner object
    }
}
