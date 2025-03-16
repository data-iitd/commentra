
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func solve(n int, ls_xyh [][]int) string {
    // Initialize the coordinates and height of the first building with a positive height
    x0 := 0
    for i := 0; i < n; i++ {
        if ls_xyh[i][2] > 0 {
            x0 = ls_xyh[i][0]
            break
        }
    }

    // Generate candidate positions (cx, cy) with their corresponding heights based on the first building
    cands := make([][]int, 0)
    for cx := 0; cx < 101; cx++ {
        for cy := 0; cy < 101; cy++ {
            cands = append(cands, []int{cx, cy, ls_xyh[0][2] + abs(cx-x0) + abs(cy-ls_xyh[0][1])})
        }
    }

    // Filter candidates based on the height constraints from the other buildings
    for i := 1; i < n; i++ {
        cands2 := make([][]int, 0)
        for _, cand := range cands {
            if max(cand[2]-abs(cand[0]-ls_xyh[i][0])-abs(cand[1]-ls_xyh[i][1]), 0) == ls_xyh[i][2] {
                cands2 = append(cands2, cand)
            }
        }
        cands = cands2
    }

    // Select the first valid candidate position and height
    xx, yy, hh := cands[0][0], cands[0][1], cands[0][2]

    // Return the result as a space-separated string
    return fmt.Sprintf("%d %d %d", xx, yy, hh)
}

func readQuestion() (int, [][]int) {
    // Read input from standard input and parse the number of buildings and their properties
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    ws := strings.Split(scanner.Text(), " ")
    n, _ := strconv.Atoi(ws[0])
    ls_xyh := make([][]int, n)
    for i := 0; i < n; i++ {
        scanner.Scan()
        ws := strings.Split(scanner.Text(), " ")
        x, _ := strconv.Atoi(ws[0])
        y, _ := strconv.Atoi(ws[1])
        h, _ := strconv.Atoi(ws[2])
        ls_xyh[i] = []int{x, y, h}
    }
    return n, ls_xyh
}

func main() {
    // Execute the solve function with the input read from readQuestion and print the result
    fmt.Println(solve(readQuestion()))
}

// Entry point of the program
func main() {
    solve(readQuestion())
}

