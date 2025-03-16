import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        sc.close();

        // Initialize a 2D array (matrix) with dimensions H x W filled with "0"
        char[][] answer = new char[H][W];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                answer[i][j] = '0';
            }
        }

        // Fill the matrix based on the conditions involving A and B
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (i < B) {
                    if (j < A) {
                        answer[i][j] = '0';
                    } else {
                        answer[i][j] = '1';
                    }
                } else {
                    if (j < A) {
                        answer[i][j] = '1';
                    } else {
                        answer[i][j] = '0';
                    }
                }
            }
        }

        // Print the resulting matrix row by row
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                System.out.print(answer[i][j]);
            }
            System.out.println();
        }
    }
}
