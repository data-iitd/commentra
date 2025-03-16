import java.util.Scanner;

public class RobotMovement {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the dimensions of the grid and the starting position
        int H = scanner.nextInt();
        int W = scanner.nextInt();
        int N = scanner.nextInt();
        
        // Read the starting position of the robot
        int s_r = scanner.nextInt();
        int s_c = scanner.nextInt();
        
        // Read the string of movements for S and T
        String S = scanner.next();
        String T = scanner.next();
        
        boolean Judge = false;  // Initialize a flag to check if the robot is out of bounds
        int S_L = 0, S_R = 0, S_U = 0, S_D = 0;  // Initialize counters for movements in each direction for S
        int T_L = 0, T_R = 0, T_U = 0, T_D = 0;  // Initialize counters for movements in each direction for T

        // Iterate through each movement in S
        for (int x = 0; x < N; x++) {
            if (S.charAt(x) == 'L') {
                S_L++;
                if (S_L - T_R - s_c == 0) {  // Check if S is about to hit the left boundary
                    Judge = true;
                }
            } else if (S.charAt(x) == 'R') {
                S_R++;
                if (s_c + (S_R - T_L) == W + 1) {  // Check if S is about to hit the right boundary
                    Judge = true;
                }
            } else if (S.charAt(x) == 'U') {
                S_U++;
                if (S_U - T_D - s_r == 0) {  // Check if S is about to hit the upper boundary
                    Judge = true;
                }
            } else if (S.charAt(x) == 'D') {
                S_D++;
                if (s_r + (S_D - T_U) == H + 1) {  // Check if S is about to hit the lower boundary
                    Judge = true;
                }
            }

            // Update the counters for T based on its movements
            if (T.charAt(x) == 'L') {
                if (S_R - T_L + s_c != 1) {  // Check if T is about to move left
                    T_L++;
                }
            }
            if (T.charAt(x) == 'R') {
                if (s_c + (T_R - S_L) != W) {  // Check if T is about to move right
                    T_R++;
                }
            }
            if (T.charAt(x) == 'U') {
                if (S_D - T_U + s_r != 1) {  // Check if T is about to move up
                    T_U++;
                }
            }
            if (T.charAt(x) == 'D') {
                if (s_r + (T_D - S_U) != H) {  // Check if T is about to move down
                    T_D++;
                }
            }
        }

        // Check the flag and print the result
        if (Judge) {
            System.out.println("NO");  // Print 'NO' if the robot is out of bounds
        } else {
            System.out.println("YES");  // Print 'YES' if the robot is within bounds
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
