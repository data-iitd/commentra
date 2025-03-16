package main
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)
func solve(n int, ls_xyh [][]int) string {
    x0 := 0
    for i := 0; i < n; i++ {
        if ls_xyh[i][2] > 0 {
            x0, y0, h0 := ls_xyh[i][0], ls_xyh[i][1], ls_xyh[i][2]
            break
        }
    }
    cands := make([][]int, 0)
    for cx := 0; cx < 101; cx++ {
        for cy := 0; cy < 101; cy++ {
            ch := h0 + abs(cx-x0) + abs(cy-y0)
            cands = append(cands, []int{cx, cy, ch})
        }
    }
    for _, xyh := range ls_xyh {
        cands = make([][]int, 0)
        for _, cand := range cands {
            cx, cy, ch := cand[0], cand[1], cand[2]
            if ch-abs(cx-xyh[0])-abs(cy-xyh[1]) >= 0 {
                cands = append(cands, []int{cx, cy, ch-abs(cx-xyh[0])-abs(cy-xyh[1])})
            }
        }
    }
    xx, yy, hh := cands[0][0], cands[0][1], cands[0][2]
    return strings.Join([]string{strconv.Itoa(xx), strconv.Itoa(yy), strconv.Itoa(hh)}, " ")
}
func readQuestion() (int, [][]int) {
    ws := strings.Split(bufio.NewReader(os.Stdin).ReadString(), " ")
    n, _ := strconv.Atoi(ws[0])
    ls_xyh := make([][]int, n)
    for j := 0; j < n; j++ {
        ls_xyh[j] = make([]int, 3)
        ls_xyh[j][0], ls_xyh[j][1], ls_xyh[j][2] = strconv.Atoi(ws[0]), strconv.Atoi(ws[1]), strconv.Atoi(ws[2])
        ws = strings.Split(bufio.NewReader(os.Stdin).ReadString(), " ")
    }
    return n, ls_xyh
}
func main() {
    n, ls_xyh := readQuestion()
    fmt.Println(solve(n, ls_xyh))
}
