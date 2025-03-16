

package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

func solve(n int, ls_xyh [][]int) string {
    // Initialize x0 to None
    x0 := -1
    
    // Find the point with a positive height
    for i := 0; i < n; i++ {
        if ls_xyh[i][2] > 0 {
            x0 = ls_xyh[i][0]
            break
        }
    }
    
    // Generate candidate points within a 101x101 grid
    cands := make([][]int, 0)
    for cx := 0; cx < 101; cx++ {
        for cy := 0; cy < 101; cy++ {
            cands = append(cands, []int{cx, cy, ls_xyh[0][2] + abs(cx - x0) + abs(cy - ls_xyh[0][1])})
        }
    }
    
    // Filter candidates to match the height of each point in ls_xyh
    for i := 0; i < n; i++ {
        cands2 := make([][]int, 0)
        for j := 0; j < len(cands); j++ {
            if max(cands[j][2] - abs(cands[j][0] - ls_xyh[i][0]) - abs(cands[j][1] - ls_xyh[i][1]), 0) == ls_xyh[i][2] {
                cands2 = append(cands2, cands[j])
            }
        }
        cands = cands2
    }
    
    // Return the coordinates of the center of the tower
    return fmt.Sprintf("%d %d %d", cands[0][0], cands[0][1], cands[0][2])
}

func readQuestion(r io.Reader) (int, [][]int) {
    // Read input from stdin and parse the number of points and their coordinates and heights
    scanner := bufio.NewScanner(r)
    scanner.Scan()
    ws := strings.Split(scanner.Text(), " ")
    n, _ := strconv.Atoi(ws[0])
    ls_xyh := make([][]int, n)
    for i := 0; i < n; i++ {
        scanner.Scan()
        ws := strings.Split(scanner.Text(), " ")
        ls_xyh[i] = make([]int, 3)
        for j := 0; j < 3; j++ {
            ls_xyh[i][j], _ = strconv.Atoi(ws[j])
        }
    }
    return n, ls_xyh
}

func main() {
    // Read input, solve the problem, and print the result
    n, ls_xyh := readQuestion(os.Stdin)
    fmt.Println(solve(n, ls_xyh))
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

