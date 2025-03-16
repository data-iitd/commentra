import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Define input variables
        int D = scanner.nextInt();
        int G = scanner.nextInt();

        // Initialize array of problems with their respective capacities
        int[][] PC = new int[D][2];
        for (int i = 0; i < D; i++) {
            PC[i][0] = scanner.nextInt();
            PC[i][1] = scanner.nextInt();
        }

        // Initialize variables for current iteration
        int ans = Integer.MAX_VALUE;

        // Loop through all possible combinations of problems
        for (int i = 0; i < (1 << D); i++) {
            // Initialize variables for current combination
            int score = 0;
            int problem = 0;

            // Calculate score for current combination
            for (int j = 0; j < D; j++) {
                // If problem j is included in current combination
                if ((i & (1 << j)) != 0) {
                    // Add score for problem j to the total score
                    score += 100 * (j + 1) * PC[j][0] + PC[j][1];
                    // Add capacity of problem j to the total problem
                    problem += PC[j][0];
                }
            }

            // If score for current combination is greater than goal G, skip to next combination
            if (score > G) {
                continue;
            }

            // Calculate remaining capacity to be covered
            int left = G - score;

            // Loop through all problems and check if they can be included in the solution
            for (int j = D - 1; j >= 0; j--) {
                // If problem j is already included in current combination, skip it
                if ((i & (1 << j)) != 0) {
                    continue;
                }

                // Check if including problem j can cover the remaining capacity
                if (left > 100 * (j + 1) * PC[j][0] + PC[j][1]) {
                    continue;
                } else {
                    // Calculate the number of instances of problem j that can be included
                    int tmp = (left + (100 * (j + 1) - 1)) / (100 * (j + 1));
                    // Update the answer if including more instances of problem j results in a better solution
                    ans = Math.min(ans, problem + Math.min(tmp, PC[j][0]));
                }
            }
        }

        // Print the answer
        System.out.println(ans);
    }
}

