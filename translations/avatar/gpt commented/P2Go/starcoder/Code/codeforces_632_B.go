package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read input (the first input is ignored)
    input, _ := bufio.NewReader(os.Stdin).ReadString('\n')

    // Read the second line of input, split it into integers and corresponding characters,
    // and create a tuple of pieces where each piece is a tuple of (score, character)
    pieces := make([][2]int, 0)
    for _, piece := range strings.Split(input, " ") {
        score, _ := strconv.Atoi(piece)
        pieces = append(pieces, [2]int{score, 'B'})
    }

    // Call the function to calculate Bob's maximum strength and return the result
    fmt.Println(Bob_sMaxStrength(pieces))
}

func Bob_sMaxStrength(pieces [][2]int) int {
    // Initialize scores for player A and player B, and their maximum scores
    pScore, sScore, pMaxScore, sMaxScore := 0, 0, 0, 0
    for _, piece := range pieces {
        if piece[1] == 'A' {  // If the piece belongs to player A
            pScore += piece[0]  // Add the score of the piece to player A's score
            if pScore > pMaxScore {  // Update maximum score if current score exceeds it
                pMaxScore = pScore
        } else {  // If the piece belongs to player B
            pScore -= piece[0]  // Subtract the score of the piece from player A's score
    }

    // Calculate maximum score for player B by iterating through pieces from the end
    for i := len(pieces) - 1; i >= 0; i-- {
        if pieces[i][1] == 'A' {  // If the piece belongs to player A
            sScore += pieces[i][0]  // Add the score of the piece to player B's score
            if sScore > sMaxScore {  // Update maximum score if current score exceeds it
                sMaxScore = sScore
        } else {  // If the piece belongs to player B
            sScore -= pieces[i][0]  // Subtract the score of the piece from player B's score
    }

    // Return the maximum score between player A and player B
    if pMaxScore > sMaxScore {
        return pMaxScore
    }
    return sMaxScore
}

