
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func solve(n int, ls_xyh [][]int) string {
    // Initialize x0 to None
    x0 := 0
    y0 := 0
    h0 := 0
    
    // Find the point with a positive height
    for i := 0; i < n; i++ {
        if ls_xyh[i][2] > 0 {
            x0 = ls_xyh[i][0]
            y0 = ls_xyh[i][1]
            h0 = ls_xyh[i][2]
            break
        }
    }
    
    // Generate candidate points within a 101x101 grid
    cands := make([][]int, 0)
    for cx := 0; cx < 101; cx++ {
        for cy := 0; cy < 101; cy++ {
            ch := h0 + abs(cx - x0) + abs(cy - y0)
            cands = append(cands, []int{cx, cy, ch})
        }
    }
    
    // Filter candidates to match the height of each point in ls_xyh
    for _, xyh := range ls_xyh {
        x := xyh[0]
        y := xyh[1]
        h := xyh[2]
        cands = filter(cands, x, y, h)
    }
    
    // Return the coordinates of the center of the tower
    (xx, yy, hh) := cands[0]
    return fmt.Sprintf("%d %d %d", xx, yy, hh)
}

func filter(cands [][]int, x, y, h int) [][]int {
    cands_new := make([][]int, 0)
    for _, cand := range cands {
        ch := max(cand[2] - abs(cand[0] - x) - abs(cand[1] - y), 0)
        if ch == h {
            cands_new = append(cands_new, cand)
        }
    }
    return cands_new
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func readQuestion() (int, [][]int) {
    // Read input from stdin and parse the number of points and their coordinates and heights
    reader := bufio.NewReader(os.Stdin)
    ws, _ := reader.ReadString('\n')
    ws = strings.TrimSpace(ws)
    ws = strings.TrimSuffix(ws, "\n")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
    ws = strings.TrimPrefix(ws, " ")
    ws = strings.TrimSuffix(ws, " ")
