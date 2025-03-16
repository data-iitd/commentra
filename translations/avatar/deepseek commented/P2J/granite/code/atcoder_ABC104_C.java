
import java.util.Scanner;

public class atcoder_ABC104_C{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int D = sc.nextInt();  // Number of problems
        int G = sc.nextInt();  // Target score
        int[][] PC = new int[D][2];  // Number of problems and bonus points for each problem
        
        // Reading the number of problems and bonus points for each problem
        for (int i = 0; i < D; i++) {
            PC[i][0] = sc.nextInt();
            PC[i][1] = sc.nextInt();
        }
        
        int ans = 100000000;  // Initializing the answer to a large number
        
        // Iterating over all possible combinations of problems using a bitmask approach
        for (int i = 0; i < (1 << D); i++) {
            int score = 0;  // Current score
            int problem = 0;  // Number of problems solved
            
            // Calculating the total score and the number of problems solved for the current combination
            for (int j = 0; j < D; j++) {
                if ((i >> j) % 2 == 1) {
                    score += 100 * (j + 1) * PC[j][0] + PC[j][1];
                    problem += PC[j][0];
                }
            }
            
            // If the total score is greater than or equal to the target score, skip to the next combination
            if (score >= G) {
                continue;
            }
            
            // Calculating the remaining score needed to reach or exceed the target score
            int left = G - score;
            
            // Checking if the remaining score can be achieved by solving additional problems
            for (int j = 0; j < D; j++) {
                if ((i >> j) % 2 == 1) {
                    continue;
                }
                if (left > 100 * (j + 1) * PC[j][0] + PC[j][1]) {
                    continue;  // If the remaining score is not enough, continue to the next problem
                } else {
                    int tmp = (left + (100 * (j + 1)) - 1) / (100 * (j + 1));  // Calculating the number of problems needed
                    ans = Math.min(ans, problem + Math.min(tmp, PC[j][0]));  // Updating the minimum number of problems solved
                }
            }
        }
        
        // Printing the minimum number of problems solved to achieve the target score
        System.out.println(ans);
    }
}
