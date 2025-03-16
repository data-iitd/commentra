

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Main function declaration

    reader := bufio.NewReader(os.Stdin)
    nTemp, err := reader.ReadString('\n')
    checkError(err)
    n := strings.TrimSpace(nTemp)

    mTemp, err := reader.ReadString('\n')
    checkError(err)
    m := strings.TrimSpace(mTemp)

    bannedRows := make(map[int]bool)
    bannedCols := make(map[int]bool)

    for i := 0; i < len(m); i++ {
        // Reading banned cells and adding them to the respective maps

        parts := strings.Split(m[i:strings.Index(m[i:], "\n")], " ")
        r, err := strconv.Atoi(parts[0])
        checkError(err)
        c, err := strconv.Atoi(parts[1])
        checkError(err)

        if r > 1 && r < len(n) {
            bannedRows[r] = true
        }
        if c > 1 && c < len(n) {
            bannedCols[c] = true
        }
    }

    answer := (len(n) - 2) * 2
    answer -= len(bannedRows)
    answer -= len(bannedCols)

    if len(n)%2!= 0 {
        // Special case when the number of rows is odd

        mid := (len(n) + 1) / 2
        if!bannedRows[mid] &&!bannedCols[mid] {
            // If the middle cell is not banned, decrement the answer
            answer--
        }
    }

    fmt.Println(answer)
    //fmt.Println("