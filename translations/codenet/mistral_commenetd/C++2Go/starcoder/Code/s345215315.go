<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

// Global variables
var ans = math.MaxInt32
var h, w int
var s [19][15]string
var dx = []int{0, 1, 0, -1, 1, 1, -1, -1}
var dy = []int{1, 0, -1, 0, 1, -1, 1, -1}

// Function to perform a depth-first search from a given position
// with a given number of steps
func dfs(x, y, cnt int) {
    // Base case: if the number of steps is greater than 20, return
    if cnt > 20 {
        return
    }

    // Print the current position, number of steps, and the current state of the grid
    // for debugging purposes
    // fmt.Println(x, y, cnt)
<<<<<<< HEAD
    // Print the current state of the grid
    // for i := 0; i < h; i++ {
    //     fmt.Println(s[i])
    // }
=======
    // fmt.Println(s)
>>>>>>> 98c87cb78a (data updated)

    // Check if the current position is the last row of the grid
    if x == h-1 {
        // Update the answer if the current number of steps is less than the previous answer
        ans = int(math.Min(float64(ans), float64(cnt)))
        return
    }

    // Iterate through all the possible directions
    for i := 0; i < 8; i++ {
        nx := x + dx[i]
        ny := y + dy[i]

        // Check if the next position is out of the grid
        if nx < 0 || nx >= h || ny < 0 || ny >= w {
            continue
        }

        // Check if the next position contains an 'X'
        if s[nx][ny]!= "X" {
            continue
        }

        // Perform a depth-first search from the next position with one more step
        c := true
        for {
            s[nx][ny] = "."
            nx += dx[i]
            ny += dy[i]
            if nx < 0 || nx >= h || ny < 0 || ny >= w {
                if nx >= h {
                    ans = int(math.Min(float64(ans), float64(cnt+1)))
                }
                c = false
                break
            }
        }

        // If the loop did not exit due to an out-of-grid position, perform the depth-first search
        if c {
            dfs(nx, ny, cnt+1)
        }

        // Backtrack by restoring the previous state of the grid
        for {
            nx -= dx[i]
            ny -= dy[i]
            s[nx][ny] = "X"
            if nx == x && ny == y {
                break
            }
        }

        // Restore the current position of the 'O'
        s[x][y] = "."
    }
}

// Main function
func main() {
    // Read the input
    fmt.Scanf("%d %d\n", &h, &w)
    for i := 0; i < h; i++ {
        s[i] = strings.Split(strings.TrimSpace(string(os.Stdin.Read(15))), "")
    }

    // Find the position of the 'O'
<<<<<<< HEAD
    sx, sy := 0, 0
=======
    sx, sy := -1, -1
>>>>>>> 98c87cb78a (data updated)
    for i := 0; i < h; i++ {
        for j := 0; j < w; j++ {
            if s[i][j] == "O" {
                sx, sy = i, j
                s[i][j] = "."
                break
            }
        }
    }

    // Perform a depth-first search from the position of the 'O' with 0 steps
    dfs(sx, sy, 0)

    // Print the answer if it is not equal to INF
    if ans == math.MaxInt32 {
        fmt.Println(-1)
    } else {
        fmt.Println(ans)
    }
}

