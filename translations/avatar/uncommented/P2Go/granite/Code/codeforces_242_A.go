
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
    var x, y, a, b int
    var games [][2]int
    var err error
    var tokens []string

    tokens, err = reader.ReadString('\n')
    if err!= nil {
        panic(err)
    }
    tokens = strings.Split(tokens[0], " ")
    x, err = strconv.Atoi(tokens[0])
    if err!= nil {
        panic(err)
    }
    y, err = strconv.Atoi(tokens[1])
    if err!= nil {
        panic(err)
    }
    a, err = strconv.Atoi(tokens[2])
    if err!= nil {
        panic(err)
    }
    b, err = strconv.Atoi(tokens[3])
    if err!= nil {
        panic(err)
    }

    for i := a; i <= x; i++ {
        if i <= b {
            continue
        }
        for j := b; j <= y; j++ {
            if i > j {
                games = append(games, [2]int{i, j})
            }
        }
    }
    fmt.Println(len(games))
    for _, game := range games {
        fmt.Printf("%d %d\n", game[0], game[1])
    }
}
