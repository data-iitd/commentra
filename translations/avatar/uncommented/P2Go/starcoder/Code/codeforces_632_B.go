package main
import "fmt"
func main() {
    var pieces [][2]int
    for _, piece := range strings.Split(fmt.Scanf("%d"), " ") {
        pieces = append(pieces, [2]int{atoi(piece), 'A'})
    }
    for _, piece := range strings.Split(fmt.Scanf("%s"), " ") {
        pieces[len(pieces)-1][1] = piece[0]
    }
    pScore, sScore := 0, 0
    pMaxScore, sMaxScore := 0, 0
    for _, piece := range pieces {
        if piece[1] == 'A' {
            pScore += piece[0]
            if pScore > pMaxScore {
                pMaxScore = pScore
        } else {
            pScore -= piece[0]
    }
    for i := len(pieces) - 1; i >= 0; i-- {
        if pieces[i][1] == 'A' {
            sScore += pieces[i][0]
            if sScore > sMaxScore {
                sMaxScore = sScore
        } else {
            sScore -= pieces[i][0]
    }
    if pMaxScore > sMaxScore {
        fmt.Printf("%d\n", pMaxScore)
    } else {
        fmt.Printf("%d\n", sMaxScore)
    }
}
func atoi(s string) int {
    i, _ := strconv.Atoi(s)
    return i
}
