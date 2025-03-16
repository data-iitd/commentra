
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
)

func main() {
    s := make([]int, 10)
    scanner := bufio.NewScanner(os.Stdin)
    for i := 0; i < 10; i++ {
        scanner.Scan()
        num, _ := strconv.Atoi(scanner.Text())
        s[i] = num
    }
    sort.Ints(s)
    for i := 9; i > 6; i-- {
        fmt.Println(s[i])
    }
}

