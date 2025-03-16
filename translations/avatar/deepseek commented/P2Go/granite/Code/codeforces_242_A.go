

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
    fmt.Println("Enter the values for x, y, a, and b:")
    text, _ := reader.ReadString('\n')
    values := strings.Split(text, " ")
    x, _ := strconv.Atoi(values[0])
    y, _ := strconv.Atoi(values[1])
    a, _ := strconv.Atoi(values[2])
    b, _ := strconv.Atoi(values[3])
    games := make([][]int, 0)
    for i := a; i <= x; i++ {
        if i <= b {
            continue
        }
        for j := b; j <= y; j++ {
            if i > j {
                games = append(games, []int{i, j})
            }
        }
    }
    fmt.Println("Number of games:", len(games))
    for _, game := range games {
        fmt.Println(game[0], game[1])
    }
}

