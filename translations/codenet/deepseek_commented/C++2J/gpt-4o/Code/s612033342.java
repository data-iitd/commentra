import java.util.Scanner;

public class Main {
    // Computes 2^a
    static int pow2(int a) {
        int ret = 1;
        for (int i = 0; i < a; i++) ret *= 2;
        return ret;
    }

    // Counts the number of 1s in the grid hw where both the i-th row and the j-th column are selected
    static int count(int[][] hw, int a, int b) {
        int sum = 0;
        for (int i = 0; i < hw.length; i++) {
            for (int j = 0; j < hw[0].length; j++) {
                if ((a >> i & 1) == 1 && (b >> j & 1) == 1 && hw[i][j] == 1) sum++;
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int h = scanner.nextInt();
        int w = scanner.nextInt();
        int k = scanner.nextInt();
        
        // Initialize the grid with dimensions h x w, filled with 0s
        int[][] hw = new int[h][w];
        
        // Read the grid and set 1s where there is a '#'
        for (int i = 0; i < h; i++) {
            String line = scanner.next();
            for (int j = 0; j < w; j++) {
                if (line.charAt(j) == '#') hw[i][j] = 1;
            }
        }
        
        int sum = 0;
        
        // Iterate over all possible combinations of row and column selections
        for (int i = 0; i < pow2(h); i++) {
            for (int j = 0; j < pow2(w); j++) {
                if (count(hw, i, j) == k) sum++; // Check if the condition is met and sum the valid combinations
            }
        }
        
        // Output the result
        System.out.println(sum);
        scanner.close();
    }
}
// <END-OF-CODE>
