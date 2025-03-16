
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var t [][]string
    var black, white, correct int
    var i, j int
    var l []string

    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    for i := 0; i < 4; i++ {
        l, _ = reader.ReadString('\n')
        l = strings.Split(strings.TrimSpace(l), " ")
        t = append(t, l)
    }

    for i := 0; i < 3; i++ {
        for j := 0; j < 3; j++ {
            if t[i][j] == "#" {
                black++
            } else {
                white++
            }

            if t[i][j+1] == "#" {
                black++
            } else {
                white++
            }

            if t[i+1][j] == "#" {
                black++
            } else {
                white++
            }

            if t[i+1][j+1] == "#" {
                black++
            } else {
                white++
            }

            if black == 0 || black == 3 || white == 0 || white == 3 || white == 4 || black == 4 {
                correct = 1
                break
            }

            black = 0
            white = 0
        }
        if correct == 1 {
            break
        }
    }

    if correct == 1 {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}

