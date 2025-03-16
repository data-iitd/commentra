import java.util.Scanner;

public class Main {
    public static void solve(int H, int W, int A, int B) {
        // Initialize a 2D array of size H x W with all elements set to "0".
        String[][] answer = new String[H][W];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                answer[i][j] = "0";
            }
        }

        // Update the array based on the given conditions.
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (i < B) {
                    if (j < A) {
                        answer[i][j] = "0";
                    } else {
                        answer[i][j] = "1";
                    }
                } else {
                    if (j < A) {
                        answer[i][j] = "1";
                    } else {
                        answer[i][j] = "0";
                    }
                }
            }
        }

        // Print the array.
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                System.out.print(answer[i][j]);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int H = scanner.nextInt();
        int W = scanner.nextInt();
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        scanner.close();

        // Call the 'solve' function with the given input.
        solve(H, W, A, B);
    }
}
