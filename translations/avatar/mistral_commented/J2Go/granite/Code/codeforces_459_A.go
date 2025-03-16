

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
    fmt.Println("Enter the first x-coordinate:")
    x1, _ := reader.ReadString('\n')
    x1 = strings.TrimSpace(x1)
    x1Int, _ := strconv.Atoi(x1)

    fmt.Println("Enter the first y-coordinate:")
    y1, _ := reader.ReadString('\n')
    y1 = strings.TrimSpace(y1)
    y1Int, _ := strconv.Atoi(y1)

    fmt.Println("Enter the second x-coordinate:")
    x2, _ := reader.ReadString('\n')
    x2 = strings.TrimSpace(x2)
    x2Int, _ := strconv.Atoi(x2)

    fmt.Println("Enter the second y-coordinate:")
    y2, _ := reader.ReadString('\n')
    y2 = strings.TrimSpace(y2)
    y2Int, _ := strconv.Atoi(y2)

    if x1Int == x2Int {
        dif := int(math.Abs(float64(y1Int - y2Int)))
        fmt.Printf("%d %d %d %d\n", x1Int+dif, y1Int, x2Int+dif, y2Int)
    } else if y1Int == y2Int {
        dif := int(math.Abs(float64(x1Int - x2Int)))
        fmt.Printf("%d %d %d %d\n", x1Int, y1Int+dif, x2Int, y2Int+dif)
    } else if int(math.Abs(float64(x1Int - x2Int))) == int(math.Abs(float64(y1Int - y2Int))) {
        fmt.Printf("%d %d %d %d\n", x1Int, y2Int, x2Int, y1Int)
    } else {
        fmt.Println(-1)
    }
}

