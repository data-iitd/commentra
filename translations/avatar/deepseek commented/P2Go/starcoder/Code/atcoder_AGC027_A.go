
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

// Function to read input and convert it to a list of integers
func na(scanner *bufio.Scanner) []int {
    var a []int
    scanner.Scan()
    for _, s := range strings.Split(scanner.Text(), " ") {
        if n, err := strconv.Atoi(s); err == nil {
            a = append(a, n)
        }
    }
    return a
}

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    n, x := na(scanner)
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i] = na(scanner)[0]
    }
    sort.Ints(a)
    ans := 0
    if a[0] > x {
        fmt.Println(0)
        return
    }
    for _, i := range a {
        if i > x {
            x = 0
            break
        }
        x -= i
        ans++
    }
    if x!= 0 {
        ans--
    }
    fmt.Println(ans)
}

