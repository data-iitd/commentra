
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
    fmt.Print("Enter a string: ")
    text, _ := reader.ReadString('\n')
    text = strings.TrimSpace(text)
    runes := []rune(text)
    x, y := 0, 0
    coordinates := make([][2]int, 0)
    coordinates = append(coordinates, [2]int{x, y})
    for _, r := range runes {
        switch r {
        case 'L':
            x--
        case 'R':
            x++
        case 'U':
            y++
        case 'D':
            y--
        }
        coordinates = append(coordinates, [2]int{x, y})
    }
    for i := 0; i < len(coordinates)-3; i++ {
        for j := i + 3; j < len(coordinates); j++ {
            dx := coordinates[i][0] - coordinates[j][0]
            dy := coordinates[i][1] - coordinates[j][1]
            if dx < 0 {
                dx = -dx
            }
            if dy < 0 {
                dy = -dy
            }
            if dx <= 1 && dy == 0 || dx == 0 && dy <= 1 {
                fmt.Println("BUG")
                return
            }
        }
    }
    fmt.Println("OK")
}

