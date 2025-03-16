
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    fmt.Println("Enter the dimensions of the grid and the number of operations")
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
    dimensions := strings.Split(input, " ")
    n, _ := strconv.Atoi(dimensions[0])
    m, _ := strconv.Atoi(dimensions[1])

    fmt.Println("Enter the coordinates of the operation")
    input, _ = reader.ReadString('\n')
    input = strings.TrimSpace(input)
    coordinates := strings.Split(input, " ")
    x, _ := strconv.Atoi(coordinates[0])
    y, _ := strconv.Atoi(coordinates[1])

    count := make([][]int, n)
    for i := 0; i < n; i++ {
        count[i] = make([]int, n)
    }

    ans := -1
    for k := 0; k < m; k++ {
        x -= 1
        y -= 1
        found := false
        for i := x - 2; i <= x + 1; i++ {
            for j := y - 2; j <= y + 1; j++ {
                if i >= 0 && i < n && j >= 0 && j < n {
                    count[i][j] += 1
                    if count[i][j] == 9 {
                        found = true
                    }
                }
            }
        }
        if found {
            ans = k + 1
            break
        }
    }
    fmt.Println(ans)
}

