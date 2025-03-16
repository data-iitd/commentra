

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(reader.ReadLine())
    solve(n)
}

func solve(n int) {
    // Calculating the result based on the given logic
    result := (n / 3) * 2
    if n%3!= 0 {
        result += 1
    }
    fmt.Println(result)
}

