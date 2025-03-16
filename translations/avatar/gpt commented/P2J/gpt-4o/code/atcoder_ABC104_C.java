import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of problems (D) and the maximum score (G) from input
        int D = scanner.nextInt();
        int G = scanner.nextInt();

        // Read the problem data, each containing the number of problems and the score for that problem
        int[][] PC = new int[D][2];
        for (int i = 0; i < D; i++) {
            PC[i][0] = scanner.nextInt(); // Number of problems
            PC[i][1] = scanner.nextInt(); // Score for that problem
        }

        // Initialize the answer to a large number (infinity)
        int ans = Integer.MAX_VALUE;

        // Iterate through all possible combinations of problems (2^D combinations)
        for (int i = 0; i < (1 << D); i++) {
            int score = 0;  // Initialize the current score
            int problem = 0;  // Initialize the count of problems solved

            // Calculate the score and number of problems solved for the current combination
            for (int j = 0; j < D; j++) {
                if ((i & (1 << j)) != 0) {  // Check if the j-th problem is included in the combination
                    score += 100 * (j + 1) * PC[j][0] + PC[j][1];  // Update score based on the problem's data
                    problem += PC[j][0];  // Update the number of problems solved
                }
            }

            // If the current score exceeds the maximum score (G), skip to the next combination
            if (score > G) {
                continue;
            }

            // Calculate the remaining score that can be achieved
            int left = G - score;

            // Check for each problem that is not included in the current combination
            for (int j = 0; j < D; j++) {
                if ((i & (1 << j)) != 0) {  // Skip if the problem is already included
                    continue;
                }

                // If the remaining score is greater than the score that can be achieved with this problem, skip
                if (left > 100 * (j + 1) * PC[j][0] + PC[j][1]) {
                    continue;
                } else {
                    // Calculate the minimum number of additional problems needed to reach the remaining score
                    int tmp = (left + (100 * (j + 1)) - 1) / (100 * (j + 1));
                    // Update the answer with the minimum number of problems solved
                    ans = Math.min(ans, problem + Math.min(tmp, PC[j][0]));
                }
            }
        }

        // Print the minimum number of problems solved to achieve the maximum score
        System.out.println(ans);
    }
}
// <END-OF-CODE>
