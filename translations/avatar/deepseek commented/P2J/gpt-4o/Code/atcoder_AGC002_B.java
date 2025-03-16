import java.util.*;
import java.io.*;

public class Main {
    // Function to read a single line of input
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static String next() throws IOException {
        if (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        // Reading the number of balls (N) and the number of operations (M)
        int N = nextInt();
        int M = nextInt();

        // Initializing the list of balls with pairs [white pieces, red pieces]
        int[][] balls = new int[N][2];

        // Special initialization for the first ball
        balls[0][0] = 0; // white pieces
        balls[0][1] = 1; // red pieces
        for (int i = 1; i < N; i++) {
            balls[i][0] = 1; // white pieces
            balls[i][1] = 0; // red pieces
        }

        // Loop to process each operation
        for (int i = 0; i < M; i++) {
            int x = nextInt() - 1; // Reading the index of the first ball (0-based)
            int y = nextInt() - 1; // Reading the index of the second ball (0-based)

            int w_x = balls[x][0]; // Extracting the current state of ball x
            int r_x = balls[x][1]; // Extracting the current state of ball x
            int w_y = balls[y][0]; // Extracting the current state of ball y
            int r_y = balls[y][1]; // Extracting the current state of ball y

            // Swapping the balls if possible
            if (w_x >= 1 && r_x >= 1) {
                balls[x][0]--;
                balls[y][1]++;
            } else if (w_x == 0) {
                balls[x][1]--;
                balls[y][1]++;
            } else {
                balls[x][0]--;
                balls[y][0]++;
            }
        }

        // Counting the number of balls with at least one red or white piece
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (balls[i][1] > 0) {
                ans++;
            }
        }

        // Printing the final count
        System.out.println(ans);
    }
}
// <END-OF-CODE>
