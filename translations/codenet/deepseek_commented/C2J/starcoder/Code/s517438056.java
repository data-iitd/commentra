import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Step 1: Reading Input
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int D = sc.nextInt();
        int i, j, k = 0, n = 0;
        double l;
        int[][] matrix = new int[N][D];
        
        // Step 2: Inputting Points
        for (i = 0; i < N; i++) {
            for (j = 0; j < D; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
        
        // Step 3: Calculating Distances
        for (i = 0; i < N - 1; i++) {
            for (j = i + 1; j < N; j++) {
                int m = 0;
                for (n = 0; n < D; n++) {
                    m = (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]) + m;
                }
                l = Math.sqrt(m);
                if (Math.ceil(l) == Math.floor(l)) k++;
            }
        }
        
        // Step 4: Outputting the Result
        System.out.println(k);
    }
}
