import java.util.*;

public class BallCollision {
    // Define constants
    static final long INF = Long.MAX_VALUE;
    static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input number of balls and number of events
        int N = scanner.nextInt();
        int M = scanner.nextInt();

        // Initialize list of balls with their weight and position
        int[][] balls = new int[N][2];
        balls[0][0] = 0; // weight of the first ball
        balls[0][1] = 1; // position of the first ball
        for (int i = 1; i < N; i++) {
            balls[i][0] = 1; // weight of other balls
            balls[i][1] = 0; // position of other balls
        }

        // Process each event
        for (int i = 0; i < M; i++) {
            // Read x and y coordinates of the event
            int x = scanner.nextInt();
            int y = scanner.nextInt();

            // Get weight and position of balls at x and y
            int w_x = balls[x - 1][0];
            int r_x = balls[x - 1][1];
            int w_y = balls[y - 1][0];
            int r_y = balls[y - 1][1];

            // Update balls' weights and positions based on the event
            if (w_x >= 1 && r_x >= 1) {
                // Ball x collides with ball y
                balls[x - 1][0] -= 1;
                balls[y - 1][1] += 1;
            } else if (w_x == 0) {
                // Ball x is stationary and ball y collides with another ball
                balls[x - 1][1] -= 1;
                balls[y - 1][1] += 1;
            } else {
                // Ball x is moving and collides with ball y
                balls[x - 1][0] -= 1;
                balls[y - 1][0] += 1;
            }
        }

        // Calculate answer
        int ans = 0;
        // Iterate through the list of balls and count the number of moving balls
        for (int i = 0; i < N; i++) {
            if (balls[i][1] > 0) {
                ans += 1;
            }
        }

        // Print the answer
        System.out.println(ans);
    }
}
// <END-OF-CODE>
