// Read the dimensions of the grid (H: height, W: width) and the number of moves (N)
Scanner sc = new Scanner(System.in);
int H = sc.nextInt();
int W = sc.nextInt();
int N = sc.nextInt();
// Read the starting position (s_r: starting row, s_c: starting column)
int s_r = sc.nextInt();
int s_c = sc.nextInt();
// Read the sequence of moves for player S
String S = sc.next();
// Read the sequence of moves for player T
String T = sc.next();

// Initialize a flag to determine if the positions collide
boolean Judge = false;

// Initialize counters for the number of moves in each direction for player S
int S_L = 0, S_R = 0, S_U = 0, S_D = 0;
// Initialize counters for the number of moves in each direction for player T
int T_L = 0, T_R = 0, T_U = 0, T_D = 0;

// Loop through each move for both players
for (int x = 0; x < N; x++) {
    // Update the move counters for player S based on the direction
    if (S.charAt(x) == 'L') {
        S_L++;
        // Check if player S's left moves match player T's right moves and the current column
        if (S_L - T_R - s_c == 0) {
            Judge = true;
        }
    } else if (S.charAt(x) == 'R') {
        S_R++;
        // Check if player S's right moves exceed the grid width
        if (s_c + (S_R - T_L) == W + 1) {
            Judge = true;
        }
    } else if (S.charAt(x) == 'U') {
        S_U++;
        // Check if player S's up moves match player T's down moves and the current row
        if (S_U - T_D - s_r == 0) {
            Judge = true;
        }
    } else if (S.charAt(x) == 'D') {
        S_D++;
        // Check if player S's down moves exceed the grid height
        if (s_r + (S_D - T_U) == H + 1) {
            Judge = true;
        }
    }

    // Update the move counters for player T based on the direction
    if (T.charAt(x) == 'L') {
        // Ensure player T's left moves do not conflict with player S's right moves
        if (S_R - T_L + s_c!= 1) {
            T_L++;
        }
    }
    if (T.charAt(x) == 'R') {
        // Ensure player T's right moves do not exceed the grid width
        if (s_c + (T_R - S_L)!= W) {
            T_R++;
        }
    }
    if (T.charAt(x) == 'U') {
        // Ensure player T's up moves do not conflict with player S's down moves
        if (S_D - T_U + s_r!= 1) {
            T_U++;
        }
    }
    if (T.charAt(x) == 'D') {
        // Ensure player T's down moves do not exceed the grid height
        if (s_r + (T_D - S_U)!= H) {
            T_D++;
        }
    }
}

// Check if there was a collision detected
if (Judge) {
    System.out.println("NO"); // Output "NO" if the positions collide
} else {
    System.out.println("YES"); // Output "YES" if the positions do not collide
}

