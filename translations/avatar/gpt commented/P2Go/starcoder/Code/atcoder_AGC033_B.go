// Read the dimensions of the grid (H: height, W: width) and the number of moves (N)
var H, W, N int
fmt.Scanf("%d %d %d\n", &H, &W, &N)
// Read the starting position (s_r: starting row, s_c: starting column)
var s_r, s_c int
fmt.Scanf("%d %d\n", &s_r, &s_c)
// Read the sequence of moves for player S
var S string
fmt.Scanf("%s\n", &S)
// Read the sequence of moves for player T
var T string
fmt.Scanf("%s\n", &T)

// Initialize a flag to determine if the positions collide
var Judge bool

// Initialize counters for the number of moves in each direction for player S
var S_L, S_R, S_U, S_D int
// Initialize counters for the number of moves in each direction for player T
var T_L, T_R, T_U, T_D int

// Loop through each move for both players
for x := 0; x < N; x++ {
    // Update the move counters for player S based on the direction
    if S[x] == 'L' {
        S_L++
        // Check if player S's left moves match player T's right moves and the current column
        if S_L - T_R - s_c == 0 {
            Judge = true
        }
    } else if S[x] == 'R' {
        S_R++
        // Check if player S's right moves exceed the grid width
        if s_c + (S_R - T_L) == W + 1 {
            Judge = true
        }
    } else if S[x] == 'U' {
        S_U++
        // Check if player S's up moves match player T's down moves and the current row
        if S_U - T_D - s_r == 0 {
            Judge = true
        }
    } else if S[x] == 'D' {
        S_D++
        // Check if player S's down moves exceed the grid height
        if s_r + (S_D - T_U) == H + 1 {
            Judge = true
        }
    }

    // Update the move counters for player T based on the direction
    if T[x] == 'L' {
        // Ensure player T's left moves do not conflict with player S's right moves
        if S_R - T_L + s_c!= 1 {
            T_L++
        }
    }
    if T[x] == 'R' {
        // Ensure player T's right moves do not exceed the grid width
        if s_c + (T_R - S_L)!= W {
            T_R++
        }
    }
    if T[x] == 'U' {
        // Ensure player T's up moves do not conflict with player S's down moves
        if S_D - T_U + s_r!= 1 {
            T_U++
        }
    }
    if T[x] == 'D' {
        // Ensure player T's down moves do not exceed the grid height
        if s_r + (T_D - S_U)!= H {
            T_D++
        }
    }
}

// Check if there was a collision detected
if Judge {
    fmt.Println("NO") // Output 'NO' if the positions collide
} else {
    fmt.Println("YES") // Output 'YES' if the positions do not collide
}

