
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(reader.ReadString('\n'))
    fmt.Println(solve(n))
}

func solve(n int) int {
    return (n / 3) * 2 + (n % 3 == 0)
}

