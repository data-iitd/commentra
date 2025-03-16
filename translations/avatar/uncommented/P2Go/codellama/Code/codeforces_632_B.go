func main() {
    input()
    pieces := make([][]int, 0)
    for _, v := range strings.Split(input(), " ") {
        pieces = append(pieces, []int{int(v[0] - '0'), int(v[1] - '0')})
    }
    return Bob_sMaxStrength(pieces)
}

func Bob_sMaxStrength(pieces [][]int) int {
    pScore := 0
    sScore := 0
    pMaxScore := 0
    sMaxScore := 0
    for _, v := range pieces {
        if v[1] == 0 {
            pScore += v[0]
            if pScore > pMaxScore {
                pMaxScore = pScore
            }
        } else {
            pScore -= v[0]
        }
    }
    for i := len(pieces) - 1; i >= 0; i-- {
        if pieces[i][1] == 0 {
            sScore += pieces[i][0]
            if sScore > sMaxScore {
                sMaxScore = sScore
            }
        } else {
            sScore -= pieces[i][0]
        }
    }
    if pMaxScore > sMaxScore {
        return pMaxScore
    }
    return sMaxScore
}

// 