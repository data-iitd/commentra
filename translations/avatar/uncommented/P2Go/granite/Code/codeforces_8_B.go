
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter the record of movements: ")
    recordOfMovements, _ := reader.ReadString('\n')
    recordOfMovements = strings.TrimSpace(recordOfMovements)

    x, y := 0, 0
    dMovement := map[string][2]int{
        "L": {0, -1},
        "R": {0, 1},
        "U": {1, 0},
        "D": {-1, 0},
    }
    d := map[[2]int]string{
        {x, y}: "",
    }
    bug := false

    for _, move := range recordOfMovements {
        temp := [2]int{x, y}
        x += dMovement[string(move)][0]
        y += dMovement[string(move)][1]
        if [2]int{x, y}!= temp {
            for step, direction := range dMovement {
                if [2]int{x + direction[0], y + direction[1]}!= temp && [2]int{x + direction[0], y + direction[1]} in d {
                    bug = true
                    break
                }
            }
        } else {
            bug = true
        }
        if bug {
            break
        }
        d[[2]int{x, y}] = ""
    }

    if bug {
        fmt.Println("BUG")
    } else {
        fmt.Println("OK")
    }
}
