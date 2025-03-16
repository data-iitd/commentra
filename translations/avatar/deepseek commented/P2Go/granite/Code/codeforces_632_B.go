

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Take input from the user
    reader := bufio.NewReader(os.Stdin)
    fmt.Fscanf(reader, "%d\n", new(int))
    // Process the input to get a slice of (value, type) pairs for each piece
    pieces := make([][2]int, 0)
    for _, piece := range strings.Split(strings.TrimSpace(readLine(reader)), " ") {
        value, _ := strconv.Atoi(piece)
        pieces = append(pieces, [2]int{value, readLine(reader)[0]})
    }
    // Call the Bob_sMaxStrength function with the processed pieces and print its result
    fmt.Println(Bob_sMaxStrength(pieces))
}

func Bob_sMaxStrength(pieces [][2]int) int {
    // Initialize scores for both ends and their maximum scores
    pScore := sScore := pMaxScore := sMaxScore := sum(pieces, func(piece [2]int) int { return piece[0] })
    
    // Calculate the score from the front (left to right)
    for _, piece := range pieces {
        if piece[1] == 'A' {
            pScore += piece[0]
            if pScore > pMaxScore {
                pMaxScore = pScore
            }
        } else {
            pScore -= piece[0]
        }
    }
    
    // Calculate the score from the back (right to left)
    for i := len(pieces) - 1; i >= 0; i-- {
        if pieces[i][1] == 'A' {
            sScore += pieces[i][0]
            if sScore > sMaxScore {
                sMaxScore = sScore
            }
        } else {
            sScore -= pieces[i][0]
        }
    }
    
    // Return the maximum score between the two ends
    if pMaxScore > sMaxScore {
        return pMaxScore
    }
    return sMaxScore
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return string(str)
    }
    panic(err)
}

func sum(slice [][2]int, mapper func([2]int) int) int {
    sum := 0
    for _, piece := range slice {
        sum += mapper(piece)
    }
    return sum
}

