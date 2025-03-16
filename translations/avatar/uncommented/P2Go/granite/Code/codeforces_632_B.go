
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println(Bob_sMaxStrength(read_pieces(reader)))
}

func read_pieces(reader *bufio.Reader) [][2]int {
    var pieces [][2]int
    var n int
    fmt.Fscanf(reader, "%d\n", &n)
    for i := 0; i < n; i++ {
        var a, b int
        fmt.Fscanf(reader, "%d %d\n", &a, &b)
        pieces = append(pieces, [2]int{a, b})
    }
    return pieces
}

func Bob_sMaxStrength(pieces [][2]int) int {
    pScore, sScore, pMaxScore, sMaxScore := 0, 0, 0, 0
    for _, piece := range pieces {
        if piece[1] == 0 {
            pScore += piece[0]
        } else {
            sScore += piece[0]
        }
    }
    pMaxScore, sMaxScore = pScore, sScore
    for i := len(pieces) - 1; i >= 0; i-- {
        if pieces[i][1] == 0 {
            pScore -= pieces[i][0]
            if pScore > pMaxScore {
                pMaxScore = pScore
            }
        } else {
            sScore -= pieces[i][0]
            if sScore > sMaxScore {
                sMaxScore = sScore
            }
        }
    }
    if pMaxScore > sMaxScore {
        return pMaxScore
    }
    return sMaxScore
}

